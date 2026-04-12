
#入力

N,M = map(int,input().split())

graph = [ ]
for _ in range(N+1):
    graph.append([])

for _ in range(M):
    a,b = map(int,input().split())
    graph[a].append(b)
    graph[b].append(a)

visited = []
for _ in range(N+1):
    visited.append(False)


def dfs(dep,cur):
    global N,visited,graph

    if dep == N:
        return 1

    ans = 0

    for dist in graph[cur]:
        if visited[dist] == False:
            visited[dist] = True
            ans += dfs(dep + 1,dist)
            visited[dist] = False
    return ans

visited[1] = True
print(dfs(1,1))
