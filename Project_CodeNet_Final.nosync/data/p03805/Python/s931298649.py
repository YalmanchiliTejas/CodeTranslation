n, m = map(int, input().split())
edge = [[False for j in range(n)] for i in range(n)]
for _ in range(m):
	a, b = map(int, input().split())
	edge[a-1][b-1] = edge[b-1][a-1] = True
visited = [False for _ in range(n)]
ans = 0
def dfs(v):
	visited[v] = True
	if all(x==True for x in visited):
		global ans
		ans += 1
		return
	for i in range(0, n):
		if edge[v][i]==True and visited[i]==False:
			dfs(i)
			visited[i] = False
dfs(0)
print(ans)