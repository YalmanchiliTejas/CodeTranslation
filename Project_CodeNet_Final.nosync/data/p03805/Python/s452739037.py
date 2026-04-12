n, m = map(int, input().split())
ab = [ list(map(int, input().split())) for _ in range(m) ]

graph = [ [False] * 8 for _ in range(8) ]
visited = [False] * n

def dfs(a, N, visited):
    finish = True
    for i in range(N):
        if not visited[i]:
            finish = False
    if finish:
        return 1
    ans = 0
    for i in range(N):
        if not graph[a][i] or visited[i]:
            continue
        visited[i] = True
        ans += dfs(i,N,visited)
        visited[i] = False
    return ans

for i in range(m):
    graph[ab[i][0]-1][ab[i][1]-1], graph[ab[i][1]-1][ab[i][0]-1] = True, True

visited[0] = True
print(dfs(0,n,visited))