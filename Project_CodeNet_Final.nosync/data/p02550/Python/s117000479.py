### ----------------
### ここから
### ----------------

import sys
from io import StringIO
import unittest
import collections
#import itertools
#import heapq
#from collections import deque
#d = deque()

def yn(b):
    print("Yes" if b==1 else "No")
    return

def resolve():
    readline=sys.stdin.readline
    cnt=collections.Counter()
    n,x,m=map(int, readline().rstrip().split())
    a=x
    if n==1:
        print(a)
        return
    t=-1
    i=2
    stock=0
    nnn=0
    ans=a
    gogo=False
    b=a
    f=-1
    while i <= n:
        a=(a*a)%m
        ans+=a
        cnt[a]+=1
        if gogo==False:
            if cnt[a] == 2:
                stock+=a
                if f<0:
                    f=i
            if cnt[a] == 3:
                ans-=a
                hani=i-f
                nokori=n-i+1
                ddd=nokori//hani
                ans+=stock*ddd
                i+=ddd*hani
                i-=1
                gogo=True
                a=b
        i+=1
        b=a
    print(ans)
    #arr=list(map(int, readline().rstrip().split()))
    #n=int(readline())
    #ss=readline().rstrip()
    #yn(1)

    return

if 'doTest' not in globals():
    resolve()
    sys.exit()

### ----------------
### ここまで 
### ----------------
