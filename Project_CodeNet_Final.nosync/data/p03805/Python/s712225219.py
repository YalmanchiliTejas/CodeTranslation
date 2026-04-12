import sys
input = sys.stdin.readline

N, M = [int(x) for x in input().split()]
G = [[] for _ in range(N + 1)]

for _ in range(M):
    a, b = [int(x) for x in input().split()]
    G[a].append(b)
    G[b].append(a)

import itertools
l = [x for x in range(2, N + 1)]
per = list(itertools.permutations(l))

cnt = 0

for i in range(len(per)):
    route = [1] + list(per[i])
    flag = 1
    for k in range(len(route) - 1):
        if route[k + 1] not in G[route[k]]:
            flag = 0
            break
    cnt += flag

print(cnt)
    