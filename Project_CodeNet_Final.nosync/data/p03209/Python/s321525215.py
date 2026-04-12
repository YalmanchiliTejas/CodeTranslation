# coding:utf-8

import sys


input = sys.stdin.readline
INF = float('inf')
MOD = 10 ** 9 + 7


def inpl(): return list(map(int, input().split()))


N, X = inpl()

ALL, P = [1], [1]
for _ in range(N):
    ALL.append(ALL[-1] * 2 + 3)
    P.append(P[-1] * 2 + 1)


# | B (X = ALL[N])
# |
# | N - 1バーガー(上)
# |
# | P (X = ALL[N] // 2 + 1)
# |
# | N - 1バーガー(下)
# |
# | B (X = 1)
def func(N, X):
    if N == 0:  # レベル0バーガー
        return 1
    if X == 1:  # 下のB
        return 0
    elif X == ALL[N]:  # 上のB
        return P[N]
    elif X == ALL[N] // 2 + 1:  # 真ん中のP
        return P[N - 1] + 1
    else:
        if X < ALL[N] // 2 + 1:  # 下のN - 1バーガー
            return func(N - 1, X - 1)
        else:  # 上のN - 1バーガー
            return func(N - 1, X - ALL[N] // 2 - 1) + P[N - 1] + 1


print(func(N, X))
