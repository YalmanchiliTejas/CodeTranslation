from sys import stderr, setrecursionlimit
from functools import reduce
from operator import add
setrecursionlimit(2147483647)
def f(n=1):
    if n == 1:
        return [int(i) for i in input().split()]
    res = []
    for i in range(n):
        res.append([int(j) for j in input().split()])
    return res
def debug(*x, sep=" ", end="\n"):
    for item in x:
        stderr.write(str(item))
        stderr.write(sep)
    stderr.write(end)

rgb = int("".join(input().split()))
print("NO" if rgb%4 else "YES")
