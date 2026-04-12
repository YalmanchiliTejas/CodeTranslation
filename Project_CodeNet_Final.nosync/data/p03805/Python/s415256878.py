class Graph(): #non-directed
    def __init__(self,n,edge):
        self.n = n
        self.graph = [[] for _ in range(n)]
        self.deg = [0 for _ in range(n)]
        for e in edge:
            self.graph[e[0] - 1].append(e[1] - 1)
            self.graph[e[1] - 1].append(e[0] - 1)
            self.deg[e[0] - 1] += 1
            self.deg[e[1] - 1] += 1

from itertools import permutations

N, M = map(int, input().split())
E = [tuple(map(int, input().split())) for _ in range(M)]

G = Graph(N, E)
res = 0

for p in permutations(range(N)):
    if p[0] != 0:
        continue
    for i in range(N - 1):
        if not p[i + 1] in G.graph[p[i]]:
            break
    else:
        res += 1

print(res)