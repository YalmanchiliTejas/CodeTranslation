from sys import stdin, setrecursionlimit
from collections import Counter, deque, defaultdict
from math import floor, ceil
from bisect import bisect_left
from itertools import combinations, accumulate
setrecursionlimit(100000)

INF = int(1e10)
MOD = int(1e9 + 7)

def main():
    from builtins import int, map
    N = int(input())
    A = list(map(int, input().split()))
    cA = list(accumulate(A))
    ans = 0
    for i in range(N - 1):
        term = A[i] * (cA[-1] - cA[i]) % MOD
        ans = (ans + term) % MOD
    print(ans)

if __name__ == '__main__':
    main()
