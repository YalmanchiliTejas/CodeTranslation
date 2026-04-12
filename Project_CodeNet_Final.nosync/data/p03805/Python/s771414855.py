import itertools

n,m = map(int,input().split())#頂点の数、辺の数

graph = [[False for i in range(n)] for j in range(n)]

for i in range(m):
    a,b = map(int,input().split())
    a -= 1
    b -= 1
    graph[a][b] = True
    graph[b][a] = True

ans = 0
for i in itertools.permutations(range(n)):
    if i[0] != 0:
        continue
    visited = [0]*n
    visited[0] += 1
    for j in range(n):
        if j == n-1:
            if 0 not in visited:
                ans += 1
            break
        if graph[i[j]][i[j+1]] == True:
            visited[i[j+1]] += 1
        
            
print(ans)
