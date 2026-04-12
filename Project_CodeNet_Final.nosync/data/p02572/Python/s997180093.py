import sys
import bisect
from functools import lru_cache
from collections import defaultdict
inf = float('inf')
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10**6)
def input(): return sys.stdin.readline().rstrip()
def read():
  return int(readline())
def reads():
  return map(int, readline().split())
n=read()
a=list(reads())
num=0
l=len(a)
ls=[]
k=0
for i in range(l-1,0,-1):
    k+=a[i]
    ls.append(k)
for i in range(l-1):
    num+=a[i]*ls[-i-1]
num%=10**9+7
print(num)