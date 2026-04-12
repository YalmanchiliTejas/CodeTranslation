import sys
from collections import Counter
from collections import deque
import heapq
import math
import fractions
import bisect
import itertools
def input(): return sys.stdin.readline().strip()
def mp(): return map(int,input().split())
def lmp(): return list(map(int,input().split()))

n=int(input())
l=deque([])
for i in range(n):
    a=int(input())
    ind=bisect.bisect_right(l,a-1)
    if ind==0:
        l.appendleft(a)
    else:
        l[ind-1]=a
print(len(l))