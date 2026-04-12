import copy

N,M = map(int, input().split())

V = []

def dfs(node, seen):

    if seen[node]==True:
        return 0

    seen[node] = True
    if not(False in seen):
        return 1
    ret = 0
    for next_node in V[node]:
        ret += dfs(next_node, copy.deepcopy(seen))
    return ret

for _ in range(N):
    V.append(set())

for _ in range(M):
    a,b = map(int, input().split())
    V[a-1].add(b-1)
    V[b-1].add(a-1)

print(dfs(0, copy.deepcopy([False]*N)))