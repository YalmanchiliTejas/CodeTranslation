import sys
import itertools
sys.setrecursionlimit(1000000000)
from heapq import heapify,heappop,heappush,heappushpop
import math
import collections
import copy
import bisect

mod = 10**9 + 7

if __name__ == "__main__":
    n = int(input())
    a = list(map(int,input().split()))
    a.sort()
    prefix = [a[0]]
    for i in range(1,n):
        prefix.append(prefix[i-1] + a[i])
    ans = 0
    for i in range(n-1):
        d = (a[i]*(prefix[-1] - prefix[i]))%mod
        ans = ans + d
        ans = ans%mod
    print(ans)