N,M = map(int,input().split())
graph = [[] for i in range(N)]
for i in range(M):
    a,b = map(int,input().split())
    graph[a-1].append(b-1)
    graph[b-1].append(a-1)

s = 0 
visited = [False]*(N)
visited[0] = True
def search(s,visited):
    if sum(visited) == N :
        return 1
    else :
        ret = 0 
        for i in graph[s]:
            if visited[i] :
                continue
            visited[i] = True 
            ret += search(i,visited)
            visited[i] = False
    return ret
print(search(s,visited))