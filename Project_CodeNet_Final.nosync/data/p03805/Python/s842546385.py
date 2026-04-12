N, M= map(int, input().split())
g = [[] for i in range(N)]
for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    g[a].append(b)
    g[b].append(a)

visited = [False] * N

def dfs(v, count):
    if visited.count(True) == N:
        return 1
    else:
        ans = 0
        for i in g[v]:
            if not visited[i]:
                visited[i] = True
                ans += dfs(i, count+1)
                visited[i] = False
        return ans

visited[0] = True
print(dfs(0,1))