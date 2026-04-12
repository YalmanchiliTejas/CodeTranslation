def li():
    return [int(x) for x in input().split()]


import itertools as it
from collections import defaultdict

N, M = li()
G = defaultdict(list)

for _ in range(M):
    a, b = li()
    G[a].append(b)
    G[b].append(a)

L = range(2, N+1)

# 順列列挙
p = it.permutations(L)
cnt = 0
for t in p:
    b = 1
    ok = True
    for i in range(len(t)):
        a, b = b, t[i]
        if b not in G[a]:
            ok = False
            break
    if ok:
        cnt += 1

print(cnt)