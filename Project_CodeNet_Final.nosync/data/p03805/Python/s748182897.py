N, M = map(int, input().split())

d = [[False for i in range(N)] for i in range(N)]
visited = [False] * N

for i in range(M):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    d[a][b] = True
    d[b][a] = True

def dfs(now, depth):
    if visited[now]:
        return 0
    if depth == N - 1:
        return 1
    
    ret = 0
    visited[now] = True

    for i in range(N):
        if d[now][i]:
            ret += dfs(i, depth + 1)
    
    visited[now] = False

    return ret

print(dfs(0,0))