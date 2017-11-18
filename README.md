# linked-list

このパターン練習repositoryのうちの1つ  
https://github.com/tanishi109/game-programming-patterns

オブザーバーパターン

単方向連結リストにオブザーバーを持って、順々にnotify処理をする感じ

```
+---------+
| Subject |
|---------|    +----------+
| head_   | -> | Observer |
+---------+    |----------|    +----------+
               | next_    | -> | Observer |
               +----------+    |----------|
                               | ...      |
                               +----------+
```

要素のremoveをポインタのポインタで書くと、headノードを特別扱いしないで書けるらしいので試した。あってるかわからない。
