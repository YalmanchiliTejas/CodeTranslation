from __future__ import division, print_function
import sys
if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

import os, sys, bisect, copy
from collections import defaultdict, Counter, deque
#from functools import lru_cache   #use @lru_cache(None)
if os.path.exists('in.txt'): sys.stdin=open('in.txt','r')
if os.path.exists('out.txt'): sys.stdout=open('out.txt', 'w')
#
def input(): return sys.stdin.readline()
def mapi(arg=0): return map(int if arg==0 else str,input().split())
#------------------------------------------------------------------


n = int(input())
a = list(mapi())
b = a[:]
for i in range(n-2,-1,-1):
    b[i] += b[i+1]
res = 0
mod =  int(1e9+7)
for i in range(n-1):
    res = (res+a[i]*b[i+1]%mod)%mod
print(res)
