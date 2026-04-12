from collections import Counter,defaultdict,deque
from bisect import bisect_left
import sys,math,itertools,pprint,fractions,time
sys.setrecursionlimit(10**8)
mod = 10**9+7
INF = float('inf')
def inp(): return int(sys.stdin.readline())
def inpl(): return list(map(int, sys.stdin.readline().split()))

s = input()
if s[0] != s[1] or s[1] != s[2]:
    print('Yes')
else: print('No')