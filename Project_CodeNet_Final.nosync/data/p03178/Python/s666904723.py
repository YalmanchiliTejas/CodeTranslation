#!/usr/bin/env python
"""<https://github.com/cheran-senthil/PyRival>"""
from __future__ import division, print_function

import sys

if sys.version_info[0] < 3:
    from __builtin__ import xrange as range
    from future_builtins import ascii, filter, hex, map, oct, zip

input = lambda: sys.stdin.readline().rstrip("\r\n")

MOD = 10**9 + 7


def main():
    K, D = list(map(int, input())), int(input())
    n = len(K)

    dp = [[0] * D for _ in range(n)]
    for i in range(10):
        dp[0][i % D] += 1
    for i in range(n - 1):
        for j in range(D):
            dp[i + 1][j] = sum(dp[i][(j - k) % D] for k in range(10)) % MOD

    cnt, k = 0, 0
    for i in range(n - 1):
        cnt = (cnt + sum(dp[-i - 2][(-j - k) % D] for j in range(K[i]))) % MOD
        k += K[i]
    cnt += sum((j + k) % D == 0 for j in range(K[-1] + 1))

    print((cnt - 1) % MOD)


if __name__ == "__main__":
    main()
