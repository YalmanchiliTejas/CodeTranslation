# Suplemental: ABC54 C
N, M = map(int, input().split())
E = [[] for i in range(N+1)]
for i in range(M):
    a,b = map(int, input().split())
    E[a].append(b)
    E[b].append(a)
    
#for i in range(1,N+1):
#    print(E[i])

visited = [False for i in range(N+1)]

num_of_paths = 0
def dfs(v):
    global num_of_paths
    
    if visited.count(True) == N:
        num_of_paths += 1
        return
    else:
        for next_v in E[v]:
            if not visited[next_v]:
                visited[next_v] = True
                dfs(next_v)
                visited[next_v] = False
        return
    
visited[1] = True
dfs(1)

print(num_of_paths)