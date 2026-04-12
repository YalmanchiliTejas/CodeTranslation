#import sys
#import numpy as np
import math
#import itertools
#from fractions import Fraction
#import itertools
from collections import deque
#import heapq
#from fractions  import gcd
#input=sys.stdin.readline
#import bisect
N,X=map(int,input().split())
l=[1]*(N+1)
p=[1]*(N+1)
for i in range(1,N+1):
    l[i]=2*l[i-1]+3
    p[i]=2*p[i-1]+1
def ans(n,x):
    if n==0:
        return 1
    if x==1:
        return 0
    elif 1<x<=l[n-1]+1:
        return ans(n-1,x-1)
    elif x==l[n-1]+2:
        return p[n-1]+1
    elif l[n-1]+2<x<=2*l[n-1]+2:
        return p[n-1]+1+ans(n-1,x-l[n-1]-2)
    else:
        return p[n-1]*2+1
print(ans(N,X))