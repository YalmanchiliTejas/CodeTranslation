#
import sys
import math
import itertools


# 整数をいくつか入力
n,x,m = (int(i) for i in input().split())

if n < 100000:
    b=0
    for i in range(n):
        b += x
        #print(x)
        x = (x*x) %m
    print(b)
else:
    ll=[0]*100000
    s=0
    for i in range(100000):
        ll[i]=x
        s += x
        x = (x*x) %m
    for i in range(99998,-1,-1):
        if ll[i]==ll[99999]:
            term=99999-i
    p=(n-100000)//term
    q=(n-100000)%term
    r=0
    for i in range(term):
        r += ll[100000-term+i]
    s += r * p
    for i in range(q):
        s += ll[100000-term+i]
    print(s)

