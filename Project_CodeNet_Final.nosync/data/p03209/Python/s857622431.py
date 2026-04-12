#!/usr/bin/env python
N, X = map(int, input().split())
MEMO = {}


def f(n):
    if n in MEMO:
        return MEMO[n]
    if n == 0:
        return 1
    MEMO[n] = f(n - 1) * 2 + 3
    return MEMO[n]


MEMO2 = {}


def g(n, i):
    if i > f(n):
        i = f(n)
    if (n, i) in MEMO2:
        return MEMO2[(n, i)]
    if n == 0:
        return 1
    ans = 0
    if i > 1:
        ans += g(n - 1, i - 1)
    if i >= 1 + f(n - 1) + 1:
        ans += 1
    if i > 1 + f(n - 1) + 1:
        ans += g(n - 1, i - 1 - f(n - 1) - 1)
    MEMO2[(n, i)] = ans
    return ans


print(g(N, X))
