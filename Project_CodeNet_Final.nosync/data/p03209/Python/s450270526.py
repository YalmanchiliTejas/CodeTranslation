#!/usr/bin/env python3

N, X = map(int, input().split())
burger_len = [1]

for i in range(N):
    burger_len += [ burger_len[i] * 2 + 3 ]

def rec(N, X):
    if X == 1:
        return 1 if N == 0 else 0
    elif 1 < X <= burger_len[N-1] + 1:
        return rec(N-1, X-1)
    elif X == burger_len[N-1] + 2:
        return rec(N-1, burger_len[N-1]) + 1
    elif burger_len[N-1] + 2 < X < burger_len[N]:
        return rec(N-1, burger_len[N-1]) + \
        1 + rec(N-1, X - burger_len[N-1] - 2)
    elif X == burger_len[N]:
        return rec(N-1, burger_len[N-1]) * 2 + 1

print (rec(N, X))
