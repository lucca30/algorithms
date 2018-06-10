# BIT - Fenwick Tree
Binary Indexed Tree or Fenwick Tree is a data structure that can update and calculate prefix and ranged operations\*.
- **f(a,b)** need to follow these rules:
    - Be **Associative**
    - Has an inverse\*\*

\* *We define prefix operation up to x for a function **f(a,b)** as below in this example, where the **f(a,b)** is sum:*
```
Prefix Sum up to X in ARR is the sum of the elements since ARR[0] to ARR[X]:
Prefix_Sum(X) = ARR[0] + ARR[1] + ARR[2] + ... + ARR[X]
```



\*\* If **f(a,b)** has no inverse operation, so you can't:
- Calculate ranged queries (you'll see that to do a ranged query **[X,Y]** where **X**>=**0** and **Y**>=**X** you will calculate the prefix **[0, X-1]** and **[0, Y]** and the you will "exclude" the **[0,X-1]** using an inverse operation )
- Replace some values in **ARR**. This is a bit hard to understand, see the explanation in the **Value Update** explanation

BIT have 4 operations (Actually 2 operations but both of then have a simple and an extended version ):
- **ByOperationUpdate**(x, val)
- **ValueUpdate**(x, val) *(an extension of By Operation Update , so you don't need the other Update) [**f(a,b)** must have inverse]*
- **PrefixedQuery**(X)
- **RangedQuery**(X,Y) *(an extension of Prefixed Query , so you don't need the other Query) [**f(a,b)** must have inverse]*


### ByOperationUpdate(x, val):
- Update the value of **ARR[x]** to **f(ARR[x], val)**

### ValueUpdate(x, val):
- Update the **ARR[x]** to **val**
- To ensure that everytimeyou call this function will work, you need to realize sometimes when you try to update the value of **ARR[x]** to **val** you need to do the inverse operation. For example:
    - **ARR[x]** = 9; **val** = 4; **f** is sum
    - So you need to **subtract** 5 of **ARR[x]**. In this case you will apply the reverse operation.

```
  Note that everytime we update something we need to apply the function f,
this occur because the tree update some ranges in the iterations and to
do this it's necessary work with the f operation instead of just update the value.
  If you really want to update a value and you can't do this using f operation, so
you need to reconstruct the BIT and spend (N log N) iterations.
```
### PrefixedQuery(x):
- Calculate the prefixed operation up to x position

### RangedQuery(x, y):
- Calculate the ranged operation since x to y position in array.
- To do this the algorithm will:
   - Calculate the  **PrefixedQuery(0, X-1)** and **PrefixedQuery(0, Y)**
   - To "exclude" the **[0,X-1]**, it's necessary use an inverse operation. So the algorithm will return **inv_f(PrefixedQuery(0, X-1), PrefixedQuery(0, Y))**

## Complexity
- **Space Complexity : ** O(N)
- **Time Complexity : ** O(log N)
