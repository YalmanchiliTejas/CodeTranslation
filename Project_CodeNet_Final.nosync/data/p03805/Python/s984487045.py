N, M = map(int, input().split())
A = [list(map(int, input().split())) for _ in range(M)]

visited = [False] * N
visited[0] = True
d = {}
for a, b in A:
    d.setdefault(b-1, []).append(a-1)
    d.setdefault(a-1, []).append(b-1)

l = sorted(d.items())

def dfs(v, seen):
    if False not in seen: return 1
    
    c = 0
    for i in d[v]:
        if (seen[i]): continue
        seen[i] = True
        c += dfs(i, seen)
        seen[i] = False
    return c
    
print(dfs(0, visited))

