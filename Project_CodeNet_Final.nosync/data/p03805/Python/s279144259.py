def dfs(x,c):
	if x==N-1:
		if all(visited):
			global ans
			ans += 1
		return

	for i in range(N):
		if neighbor[c][i] and not visited[i]:
			visited[i] = True
			dfs(x+1,i)
			visited[i] = False
		
N, M = map(int,input().split())
edge = [[int(i) for i in input().split()] for i in range(M)]
neighbor = [[False for i in range(N)] for i in range(N)]
visited = [False for i in range(N)]
for i in range(M):
	neighbor[edge[i][0]-1][edge[i][1]-1] = True
	neighbor[edge[i][1]-1][edge[i][0]-1] = True
	
ans = 0
visited[0] = True
dfs(0,0)
print(ans)
