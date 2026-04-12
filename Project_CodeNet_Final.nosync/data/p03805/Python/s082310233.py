N, M = map(int, input().split())
G = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(lambda x:int(x)-1, input().split())
    G[a].append(b)
    G[b].append(a)

from itertools import permutations
c = 0
for p in permutations(range(1, N)):
    pi = 0
    for pj in p:
        if not pj in G[pi]:
            break
        pi = pj
    else:
        c += 1
print(c)