n,m = map(int,input().split())
edge = [[] for i in range(n)]
for i in range(m):
    x,y = map(int,input().split())
    edge[x-1].append(y-1)
    edge[y-1].append(x-1)
def dfs(visited,i):
    visited.append(i)
    if len(visited) == n:
        return 1
    count = 0
    for j in edge[i]:
        if j in visited:
            continue
        count += dfs(visited[:],j)
    return count
print(dfs([],0))