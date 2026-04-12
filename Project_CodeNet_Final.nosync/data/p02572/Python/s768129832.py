import math
import pprint
import fractions
import collections
import itertools
from decimal import *
from collections import deque
from bisect import *
N=int(input())
A=list(map(int,input().split()))
cuml=[0]*N
p=10**9+7
for i in range(N-1):
    cuml[i+1]=(cuml[i]+A[i])%p
#print(cuml)
ans=0
for i in range(N):
    ans=(ans+A[i]*cuml[i])%p
print(ans)

