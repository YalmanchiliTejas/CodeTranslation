def dfs(v,been):
    if len(been) == n:
        ans.append(1)
        #print(been)
        return
    for i in graph[v]:
        if i in been:
            pass
        else:
            been.add(i)
            dfs(i,been)
            been.remove(i)
    return

n,m = map(int,input().split())
graph = [[] for _ in range(n+1)]
for _ in range(m):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)
#print(graph)

ans = []

dfs(1,set([1]))
print(sum(ans))