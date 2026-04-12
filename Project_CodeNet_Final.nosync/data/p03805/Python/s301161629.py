N,M = map(int,input().split())

A = [list(map(int, input().split()))  for i in range(M)]

graph_data = [[0] * N for i in range(N)]

for i in range(M):
    if A[i][0] > A[i][1]: A[i][0], A[i][1] = A[i][1], A[i][0]
    graph_data[A[i][0]-1][A[i][1]-1] = graph_data[A[i][1]-1][A[i][0]-1] = 1
    
visited = [False] * N

def dfs(now, depth):
    if visited[now]:
        return 0
    if depth == N - 1:
        return 1
    
    visited[now] = True
    total_path = 0
    for i in range(0,N):
        if graph_data[now][i] == 1: 
            total_path +=  dfs(i, depth + 1)
    visited[now] = False
    
    return total_path

print(dfs(0,0))