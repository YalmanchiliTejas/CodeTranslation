from math import *
from collections import *
from itertools import *
from functools import *
from bisect import *
from heapq import *
from operator import *
from sys import *
setrecursionlimit(100000000)
MAX=float('inf')
MIN=float('-inf')
MOD=1000000007

n=int(input())
l=list(map(int,input().split()))
l1=list(accumulate(l[::-1]))[::-1]
ans=0
for i in range(1,len(l1)):
	ans+=(l[i-1]*l1[i])%MOD
print(ans%MOD)
