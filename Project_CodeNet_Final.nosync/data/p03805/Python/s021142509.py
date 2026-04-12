N,M=[int(i) for i in input().split()]
edge=[[] for i in range(N)]

for i in range(M):
	a,b=[int(i)-1 for i in input().split()]
	edge[a].append(b)
	edge[b].append(a)

went=[False for i in range(N)]

def dfs(now):
	if went.count(False)==0:
		return 1
	ans=0
	for _next in edge[now]:
		if not went[_next]:
			went[_next]=True
			ans+=dfs(_next)
			went[_next]=False
	return ans
went[0]=True

print(dfs(0))
