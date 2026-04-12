import math,string,itertools,fractions,heapq,collections,re,array,bisect,sys,random,time

sys.setrecursionlimit(10**7)
inf = 10**10
mod = 10**9 + 7


def f():
    h,w = list(map(int, input().split()))
    a = [input() for _ in range(h)]
    c = 0
    for i in range(h):
        for j in range(w):
            if a[i][j] == '#':
                c += 1
    if c == h + w -1:
        return 'Possible'
    return 'Impossible'


print(f())
