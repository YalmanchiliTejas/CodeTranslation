n,m=map(int,input().split())
graph = [[] for _ in range(n)]
for i in range(m):
    a, b=map(int, input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

def dfs(v, seen):
    if all(seen):
        return 1
    ans=0
    for i in graph[v]:
        if seen[i]:
            continue
        seen[i]=True
        # print(seen)
        ans+=dfs(i, seen)
        seen[i]=False
    return ans

seen=[False]*n
seen[0]=True
print(dfs(0, seen))
