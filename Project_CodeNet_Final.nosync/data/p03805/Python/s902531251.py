n,m = map(int,input().split())
graph = [[0 for i in range(n)] for j in range(n)]

for i in range(m):
    a,b =  map(int,input().split())
    graph[a-1][b-1] = 1
    graph[b-1][a-1] = 1

count = 0
visited = [0]*n
def dfs(initial,graph,visited):
    global count
    all_visited = True
    visited[initial] = 1
    for i in visited:
        if i == 0:
            all_visited = False 
            
    if all_visited == True:
        count += 1
        return 0
    
    for i in range(n):
        if graph[initial][i] ==1:
            if visited[i] == 0:
                visited[i] = 1
                dfs(i,graph  ,visited)
                visited[i] = 0
    return count


print(dfs(0 ,graph , visited ))