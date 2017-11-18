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
    void removeObserver(Observer* observer);
    void removeObserver2(Observer** observer);
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

void Subject::removeObserver(Observer* observer)
{
    if (observer == head_) {
        head_ = head_->next_;
        observer->next_ = NULL;
        return;
    }

    Observer* current = head_;
    while(current != NULL)
    {
        if (current->next_ == observer) {
            current->next_ = observer->next_;
            observer->next_ = NULL;
            return;
        }
        current = current->next_;
    }
}

void Subject::removeObserver2(Observer** observer)
{
    Observer** current = &head_;
    while(*current != NULL)
    {
        if (*observer == *current) {
            printf("*** remove observer; value = %d\n", (*current)->value_);
            *current = (*current)->next_;
            (*observer)->next_ = NULL;
            return;
        }
        current = &((*current)->next_);
    }
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

    printf("== register == \n");

    Observer* ob1 = new Observer(123);
    sub->addObserver(ob1);
    Observer* ob2 = new Observer(456);
    sub->addObserver(ob2);
    Observer* ob3 = new Observer(789);
    sub->addObserver(ob3);
    sub->notify();

    printf("== remove == \n");

    sub->removeObserver2(&ob3);
    sub->notify();

    system("pause");
    return 0;
}

