import sys
import heapq
import math
import fractions
import bisect
import itertools
from collections import Counter
from collections import deque
from operator import itemgetter
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

mod=10**9+7
n=int(input())
a=lmp()
s=sum(a)%mod
ans=0
for i in range(n):
    s-=a[i]
    s%=mod
    ans+=a[i]*s
    ans%=mod
print(ans)
