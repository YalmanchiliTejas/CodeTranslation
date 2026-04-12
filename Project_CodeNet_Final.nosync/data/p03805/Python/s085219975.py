n, m = map(int, input().split())
A = [[int(i) for i in input().split()] for i in range(m)]

vis = [0] * n
vis[0] = 1

G = [[0] * n for i in range(n)]
for a, b in A:
    G[a -1][b - 1] = 1
    G[b - 1][a - 1] = 1
    
cnt = 0
    
def dfs(x):
    global cnt
    if sum(vis) == n:
        cnt += 1
        return
    for i in range(n):
        if G[x][i] == 1 and vis[i] == 0:
            vis[i] = 1
            dfs(i)
            vis[i] = 0
    return

dfs(0)
print(cnt)