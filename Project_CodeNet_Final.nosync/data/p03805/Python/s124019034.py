n, m = map(int, input().split())
mat = [[] for _ in range(n)]
for _ in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    mat[a].append(b)
    mat[b].append(a)

ans = 0
def dfs(visited, current):
    global ans
    if len(visited) == n:
        ans += 1
        return
    for nex in mat[current]:
        if nex not in visited:
            _vi = visited[:]
            _vi.append(nex)
            dfs(_vi, nex)

dfs([0], 0)
print(ans)