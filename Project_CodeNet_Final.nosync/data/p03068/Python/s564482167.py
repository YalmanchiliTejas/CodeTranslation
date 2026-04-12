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

n=int(input())
s=list(input())
k=int(input())
a=s[k-1]
for i in range(n):
    if s[i]!=a:
        s[i]="*"
print(*s,sep="")