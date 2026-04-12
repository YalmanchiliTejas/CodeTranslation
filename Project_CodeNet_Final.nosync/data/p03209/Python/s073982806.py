# -*- coding: utf-8 -*-

N, X = map(int, input().split())

L, P = [1], [1]
for i in range(N - 1):
    L.append(L[-1] * 2 + 3)
    P.append(P[-1] * 2 + 1)


def countPatty(N, X):
    if N == 0:
        return 1 if X >= 1 else 0
    elif X <= 1:
        return 0
    elif 1 < X <= L[N - 1] + 1:
        return countPatty(N - 1, X - 1)
    elif L[N - 1] + 1 < X:
        return P[N - 1] + 1 + countPatty(N - 1, X - (L[N - 1] + 2))


print(countPatty(N, X))
