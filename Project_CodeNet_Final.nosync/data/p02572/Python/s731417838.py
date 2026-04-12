import os
import sys
import math
import heapq
from decimal import *
from io import BytesIO, IOBase
from collections import defaultdict, deque

def r():
    return int(input())
def rm():
    return map(int,input().split())
def rl():
    return list(map(int,input().split()))

mod=1000000007
n = r()
a = rl()
b = [a[-1]]
for i in range(n-2,-1,-1):
    b.append(b[-1]+a[i])
b = b[::-1]
ans = 0
for i in range(n-1):
    ans= (ans+(a[i]*b[i+1])%mod)%mod
print(ans)