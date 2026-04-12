from itertools import permutations

N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x: int(x)-1, input().split())
    G[a].append(b)
    G[b].append(a)

ans = 0
for p in permutations(range(1, N)):
    v = 0
    flag = True
    for nv in p:
        if nv not in G[v]:
            flag = False
            break
        v = nv
    if flag:
        ans += 1

print(ans)