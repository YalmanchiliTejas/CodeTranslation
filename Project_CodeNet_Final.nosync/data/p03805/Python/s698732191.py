N, M = map(int, input().split())
 
if M == 0:
    print(0)
    exit()
    
es = [[] for i in range(M+1)]
for i in range(M):
    a, b = map(int, input().split())
    a,b = a-1, b-1
    es[a].append(b)
    es[b].append(a)

def dfs(v, visited, es, cnt):
 
    #print("--------------")
    #print((v, visited, cnt))
 
    if cnt == N-1:
        return 1
    ret = 0
    for i in es[v]:
        if visited[i] == True:
            continue
 
        visited[i] = True
        ret += dfs(i, visited, es, cnt+1)
        visited[i] = False
 
    return ret
 
visited = [False] * N
visited[0] = True
 
ans = dfs(0,visited,es,0)
print(ans)