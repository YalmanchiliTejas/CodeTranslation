import sys
from bisect import *

input=sys.stdin.readline

def f(n):
    mi=-1
    r = [inf]*n
    for _ in range(n):
        a = -int(input())
        i = bisect_right(r, a)
        r[i]=a
        if i>mi:
            mi=i
    print(mi+1)

n = int(input())
inf=10**10
f(n)
