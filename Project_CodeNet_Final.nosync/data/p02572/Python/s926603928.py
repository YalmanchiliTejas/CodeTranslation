import sys
sys.setrecursionlimit(4100000)
import math
import itertools
INF = float('inf')
from heapq import heapify, heappop, heappush

def main():
    n = int(input())
    A = list(map(int, input().split()))

    mod = 10**9 + 7
    s = sum(A)
    ans = 0
    for i in range(n):
        s -= A[i]
        ans += A[i]*s
    print(ans%mod)


if __name__ == '__main__':
    main()
