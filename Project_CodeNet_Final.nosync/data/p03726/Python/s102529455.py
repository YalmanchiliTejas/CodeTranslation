n=int(input())
g=[[] for i in range(n+1)]
for i in range(n-1):
	u,v=map(int,input().split())
	g[u]+=[v]
	g[v]+=[u]
def dfs(x,p):
	s=sum([dfs(u,x) for u in g[x] if u!=p])
	return s^1 if s<2 else 2
print("First" if dfs(1,1) else "Second")