#!/usr/bin/env python3
from itertools import permutations
n, m = map(int, input().split())
G = [[] for _ in [0] * -~n]
for _ in [0] * m:
    a, b = map(int, input().split())
    G[a] += b,
    G[b] += a,
ans = 0
for i in permutations(range(2, n + 1), n - 1):
    i = (1,) + i
    if all(i[j] in G[i[j + 1]] for j in range(n - 1)):
        ans += 1
print(ans)