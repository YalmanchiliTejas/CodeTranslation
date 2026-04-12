#!/usr/bin/env python3
# -*- coding: utf-8 -*-

# F - Select Half

n = int(input())
a = list(map(int, input().split()))
assert len(a) == n

# memo[i][m] a[0:i+1]からm個選ぶときの最大値
memo = [{} for i in range(n)]
memo[0] = {0: 0, 1: a[0]}
memo[1] = {1: max(a[:2])}

for i in range(2, n):
    m = (i + 1) // 2
    memo[i][m] = max(memo[i - 1][m], memo[i - 2][m - 1] + a[i])
    if i % 2 == 0:
        memo[i][m + 1] = memo[i - 2][m] + a[i]

print(memo[-1][n // 2])
