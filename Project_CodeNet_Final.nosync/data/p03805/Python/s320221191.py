N, M = map(int, input().split())
pathmat=[[0]*N for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    pathmat[a-1][b-1] = 1
    pathmat[b-1][a-1] = 1

visited =  [False]*N
visited[0] = True


def DFS(now, visited):
    if all(visited):
        return 1
    ans = 0
    for i in range(N):
        if not pathmat[now][i]:
            continue
        if visited[i]:
            continue
        visited[i]=True
        ans += DFS(i, visited)
        visited[i]=False
    return ans

print(DFS(0,visited))

        
            
