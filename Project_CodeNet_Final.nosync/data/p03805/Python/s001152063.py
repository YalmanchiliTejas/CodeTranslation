from collections import deque

n,m = map(int,input().split())
edge_li = [[] for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    edge_li[a-1].append(b-1)
    edge_li[b-1].append(a-1)

stack = deque([0])
visited = [False]*n
visited[0] = True

def dfs(visited,stack):
    tmp = 0
    while stack:
        x = stack.pop()
        if all(visited):
            return 1
        for e in edge_li[x]:
            if visited[e]:
                continue
            visited[e]=True
            stack.append(e)
            tmp+=dfs(visited,stack)

            visited[e]=False
    return tmp

print(dfs(visited,stack))