#from math import *
import fractions
import sys
import collections
import itertools
import pprint
from collections import deque
from heapq import *
import copy
N,X,M=map(int,input().split())
l=[0]*(M+1)
l[X]=1
X2=X
ans=0
for i in range(10**5+1):
    #print(X)
    X=pow(X,2,M)
    if l[X]==0:
        l[X]=i+2
    else:
        start=l[X]
        end=i+2
        #print(i+1,l[X])
        break
#print(l)
res=[]
X=X2
loop=[]
#print(start,end)
for i in range(start-1):
    res.append(X)
    X=pow(X,2,M)
for i in range(start,end):
    loop.append(X)
    X=pow(X,2,M)
#print(res,loop)
loopsum=sum(loop)
if N<=len(res):
    for i in range(N):
        ans=ans+res[i]
else:
    for i in range(len(res)):
        ans=ans+res[i]
    loopnum=(N-len(res))//len(loop)
    loopres=(N-len(res))%len(loop)
    for i in range(loopres):
        ans=ans+loop[i]
    ans=ans+loopnum*loopsum
print(ans)