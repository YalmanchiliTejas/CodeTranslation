N,M = map(int,input().split())

path = [[] for i in range(N)]

for _ in range(M):
	a,b = map(int,input().split())
	path[a-1].append(b-1)
	path[b-1].append(a-1)
vis = [0 for i in range(N)]
cnt = 0

def dfs(now,depth):
	global cnt
	if depth == N: cnt+=1
	for new in path[now]:
		if vis[new] == 0:
			vis[new] = 1
			dfs(new,depth+1)
			vis[new] = 0

vis[0] = 1
dfs(0,1)
print(cnt)
