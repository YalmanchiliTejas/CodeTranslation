N, M = map(int,input().split())
G = [[0]*N for _ in range(N)]
edge = []
for i in range(M) :
    a, b = map(int,input().split())
    edge.append([a-1, b-1])
    G[a-1][b-1] = G[b-1][a-1] = 1

visited = [0]*N
visited[0] = 1

def dfs(n) :
    ans = 0
    if min(visited) == 1 :
        return 1
    for i in range(N) :
        if G[n][i] == 1 and visited[i] == 0 :
            visited[i] = 1
            ans += dfs(i)
            visited[i] = 0
    return ans

print(dfs(0))
