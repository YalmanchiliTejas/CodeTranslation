from bisect import *
from collections import *
from fractions import gcd
from math import factorial
from itertools import *
from heapq import *
import copy

N,X=map(int,input().split())

P=[0 for i in range(N+1)]
P[0]=1
PB=[0 for i in range(N+1)]
PB[0]=1
for i in range(1,N+1):
    P[i]=1+2*P[i-1]
    PB[i]=3+2*PB[i-1]

count=0
idx=N

while X>0:
    A=PB[idx]
    if X>=A:
        X-=A
        count+=P[idx]
        if X>=1:
            count+=1
            X-=1
    else:
        X-=1
        idx-=1
print(count)
