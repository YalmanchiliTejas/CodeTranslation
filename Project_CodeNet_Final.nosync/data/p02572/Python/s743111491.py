import sys
import bisect
import itertools
import collections
import fractions
import heapq
import math
from operator import mul
from functools import reduce
from functools import lru_cache


def solve():

    readline = sys.stdin.buffer.readline
    mod = 10 ** 9 + 7
    N = int(input())
    A = list(map(int, input().split()))
    sumnation = 0
    def modinv(a, mod=10 ** 9 + 7):
        return pow(a, mod - 2, mod)
    twoinv = modinv(2, mod)
    for i in A:
        sumnation += (i % mod)
        sumnation %= mod

    ans = pow(sumnation, 2, mod)
    for i in A:
        ans -= pow(i, 2, mod)
        while ans < 0:
            ans += mod
    ans *= twoinv
    ans %= mod
    print(ans)


if __name__ == '__main__':
    solve()