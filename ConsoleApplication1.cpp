// ConsoleApplication1.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include <stdlib.h>

class Observer;
class Subject
{
public:
    Subject()
    :  head_(NULL)
    {}

    void addObserver(Observer* observer);
    void notify();
private:
    Observer* head_;
};

class Observer
{
    friend class Subject;
public:
    int value_;

    Observer(int v)
    : next_(NULL),
      value_(v)
    {}

private:
    Observer* next_;

    void onNotify()
    {
        printf("notify! #%d\n", this->value_);
    }
};

void Subject::addObserver(Observer* observer)
{
    observer->next_ = head_;
    head_ = observer;
}

void Subject::notify()
{
    Observer* observer = head_;
    while (observer != NULL)
    {
        observer->onNotify();
        observer = observer->next_;
    }
}

int main()
{
    Subject* sub = new Subject();

    for (int i = 0; i < 10; i++)
    {
        Observer* ob = new Observer(i);
        sub->addObserver(ob);
    }

    sub->notify();

    system("pause");
    return 0;
}

