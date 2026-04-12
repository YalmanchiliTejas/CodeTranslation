from collections import defaultdict as ddic, deque, Counter
from itertools import permutations, combinations, product
import bisect, heapq

rr = raw_input
rri = lambda: int(raw_input())
rrm = lambda: map(int, raw_input().split())
MOD = 10**9 + 7

def binom(n, k):
    numer = 1
    for i in xrange(1, n+1):
        numer *= i
        numer %= MOD
    denom = 1
    for i in xrange(1, k+1):
        denom *= i
        denom %= MOD
    denom2 = 1
    for i in xrange(1, n-k+1):
        denom2 *= i
        denom2 %= MOD
    ans = numer * pow(denom, MOD-2, MOD) % MOD
    ans *= pow(denom2, MOD-2, MOD)
    ans %= MOD
    return ans

def sumToN(N):
    return N*(N+1)/2

def flat(R, C):
    if C > R: R,C = C,R
    # R >= C
    # 0 1 2 3 4 5 6 7 8 [C=9]
    # 3 2 1 0 1 2 3 4 5
    ans = 0
    for c in xrange(C):
        left = c
        right = C - 1 - c
        base = sumToN(left) + sumToN(right)
        for r in xrange(R):
            up, down = r, R-1-r
            base2 = sumToN(up) + sumToN(down)
            ans += base * R + base2 * C
    ans /= 2
    return ans % MOD


def solve(R, C, K):
    N = R * C
    return flat(R, C) * binom(N - 2, K - 2) % MOD

print solve(*rrm())
