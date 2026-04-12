n,m=map(int,input().split())
edges=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    a-=1; b-=1
    edges[a].append(b)
    edges[b].append(a)
visited=[False]*n
visited[0]=True
cnt=0

def dfs(fr):
    global cnt
    if all(visited):
        cnt+=1
        return
    for to in edges[fr]:
        if not visited[to]:
            visited[to]=True
            dfs(to)
            visited[to]=False
    return

dfs(0)
print(cnt)