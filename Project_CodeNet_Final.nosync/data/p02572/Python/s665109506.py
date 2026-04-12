#!/usr/bin/env python3
import sys
from collections import deque, Counter
from heapq import heappop, heappush
from bisect import bisect_right
from itertools import accumulate

sys.setrecursionlimit(10**6)
INF = 10**12
m = 10**9 + 7

def main():
    N = int(input())
    A = list(map(int, input().split()))
    ans = 0
    for i in range(N):
        ans += A[i]
        ans %= m
    ans = ans**2
    ans %= m
    for i in range(N):
        ans -= pow(A[i],2,m)
        ans %= m
    
    ans = ans * pow(2,m-2,m) % m
    print(ans)

if __name__ == "__main__":
    main()