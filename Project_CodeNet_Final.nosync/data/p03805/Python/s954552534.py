n,m=map(int,input().split())
graph=[[] for _ in range(n)]
for _ in range(m):
    a,b=map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def dfs(v, seen):
    if all(seen):
        return 1
    ans=0
    for vv in graph[v]:
        if seen[vv]:
            continue
        seen[vv]=True
        ans+=dfs(vv, seen)
        seen[vv]=False
    return ans

seen=[False]*n
seen[0]=True
print(dfs(0, seen))
