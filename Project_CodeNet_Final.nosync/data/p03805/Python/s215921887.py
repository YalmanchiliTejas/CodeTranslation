N,M = map(int,input().split())
T = {}
for i in range(M):
    a,b = map(int,input().split())
    if a not in T.keys():
        T[a] = []
    if b not in T.keys():
        T[b] = []
    T[a].append(b)
    T[b].append(a)

ans = 0
def dfs(graph,start,path):
    global ans
    global N
    path = path + [start]

    if len(path) == N:
        ans += 1

    for node in graph[start]:
        if node not in path:
            new = dfs(graph,node,path)

    return ans


print(dfs(T,1,[]))
