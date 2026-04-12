from collections import *
from heapq import *
from itertools import *
from fractions import gcd
import sys
from decimal import *
import copy
from bisect import *
input=lambda :sys.stdin.readline().rstrip()
N,K=map(int,input().split())
if K==0:
    print(N**2)
    exit()
count=0
for b in range(K+1,N+1):
    count+=(N//b)*(b-K)
    count+=max(N%b-(K-1),0)
print(count)
