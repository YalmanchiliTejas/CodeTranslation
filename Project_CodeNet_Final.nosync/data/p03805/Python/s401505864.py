N,M=map(int,input().split())
G=[[False]*(N+1) for _ in range(N+1)]
for i in range(M):
    a,b=map(int,input().split())
    G[a][b]=True
    G[b][a]=True

visited=[False]*(N+1)

visited[1]=True
def dfs(start):
    global N
    global visited
    all_visited=True
    sum=0

    for p in range(1,N+1):
        if not visited[p]:
            all_visited=False

    if all_visited:
        return 1
    else:
        for next in range(1,N+1):#N小より全探索
            if not G[start][next]:
                continue
            if visited[next]:
                continue
            visited[next]=True
            sum+=dfs(next)
            visited[next]=False   #backtrack

        return sum

print(dfs(1))
