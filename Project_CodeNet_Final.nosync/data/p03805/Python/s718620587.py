import collections
N,M = list(map(int,input().split()))
tree = [[] for _ in range(N)]
for _ in range(M):
    u, v = map(int, input().split())
    tree[u - 1].append(v - 1)  ##無効グラフであるので
    tree[v - 1].append(u - 1)




def dfs(now,prev,visited):
    
    if sum(visited) == 0:
        return 1
    
    ret = 0
    
    for nxt in tree[now]:
        if nxt != prev and visited[nxt] == 1:
            visited[nxt] = 0
            ret += dfs(nxt,now,visited)
            visited[nxt] = 1
    return ret
            
visited = [1 for _ in range(N)]
visited[0] = 0
print(dfs(0,-1,visited))
