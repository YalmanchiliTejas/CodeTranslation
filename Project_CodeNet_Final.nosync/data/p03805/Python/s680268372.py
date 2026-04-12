#!/usr/bin/env python3
import itertools


N, M = [int(str) for str in input().strip().split()]
ab = [[int(str) - 1 for str in input().strip().split()] for _ in range(M)]


def solve():
    G = [[False] * N for _ in range(N)]
    for a, b in ab:
        G[a][b] = True
        G[b][a] = True
    ans = 0
    for p in itertools.permutations(range(1, N), N - 1):
        pp = [0] + list(p)
        ans += all([G[pp[i]][pp[i + 1]] for i in range(N - 1)])
    print(ans)

solve()
