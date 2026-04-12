import bisect
import collections
import copy
import functools
import heapq
import math
import sys
from collections import deque
from collections import defaultdict
input = sys.stdin.readline
MOD = 10**9+7

N = int(input())
s = list(input().rstrip())
s.append(s[0])
a = [-1]*(N+2) # 0==N 1==N+1

def d(self,f,ans):
    if ans == "o":
        return (self + f)%2
    else:
        return (self + f +1)%2

flag = 0
for p in [(0,0),(0,1),(1,0),(1,1)]:
    a[0],a[1] = p
    for i in range(1,N+1):
        a[i+1] = d(a[i],a[i-1],s[i])
    if a[0] == a[N] and a[1] == a[N+1]:
        break
else:
    flag = -1

if flag == -1:
    print(-1)
else:
    ans = [None]*N
    for i in range(N):
        if a[i] == 0:
            ans[i] = "S"
        else:
            ans[i] = "W"
    output = "".join(ans)
    print(output)