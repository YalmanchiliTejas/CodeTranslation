import sys
sys.setrecursionlimit(10**9)

n, m = map(int, input().split())
g = [[] for i in range(n+1)] #隣接リスト
for i in range(m):
    a, b = map(int, input().split())
    g[a].append(b)
    g[b].append(a)

visited = [False] * (n+1)
visited[0] = True
visited[1] = True
cnt = 0

def dfs(list):
    global cnt
    if not False in visited:
        cnt += 1
        return
    for i in list:
        if visited[i] == False:
            visited[i] = True
            dfs(g[i])
            visited[i] = False

dfs(g[1])
print(cnt)
