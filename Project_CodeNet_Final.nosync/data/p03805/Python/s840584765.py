N, M = map(int,input().split())
graph = []
for i in range(N):
    graph.append([])

#頂点の番号はindex+1
for i in range(M):
    a, b = map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

visited = []
for i in range(N):
    visited.append(0)
visited[0] = 1

#print(graph)

ans = 0

#jを訪れたときはvisited[j]が1になる

def dfs(v):
    global ans
    global visited
    kita = 0
    for k in visited:
        if k == 1:
            kita += 1
        
    if kita == N:
        ans += 1
    

    for j in graph[v]:
        #print(j)
        if visited[j] == 1:
            continue
        visited[j] = 1
        dfs(j)
        visited[j] = 0


dfs(0)

print(ans)
    
