n, m = map(int, input().split())
e = [set([]) for _ in range(n+1)] # e[0] never used
for _ in range(m):
    a, b = map(int, input().split())
    e[a].add(b)
    e[b].add(a)

ans = 0
visited = [False]*(n+1) # visited[0] never used
visited[0] = True
def dfs(v):
    # current pos is v
    global visited
    global ans
    if all(v==True for v in visited):
        ans += 1
        return
    
    for next_pos in e[v]:
        if visited[next_pos] != True:
            visited[next_pos] = True
            dfs(next_pos)
            visited[next_pos] = False

visited[1] = True
dfs(1)
print(ans)