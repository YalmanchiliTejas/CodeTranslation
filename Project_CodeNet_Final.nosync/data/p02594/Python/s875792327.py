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
X=read()
if(X>=30):
    print("Yes")
else:
    print("No")