N, M = map(int, input().split())
graph ={i+1:[] for i in range(N)}
for _ in range(M):
    a, b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
def dfs(path, n, cnt):
    if(len(path) == N):
        return cnt+1
    for j in graph[n]:
        if(j in path):
            continue
        cnt = dfs(path+[j], j, cnt)
    return cnt
print(dfs([1], 1, 0))