n=int(input())
g=[[] for i in range(n)]
for i in range(n-1):
	u,v=map(lambda x:int(x)-1,input().split())
	g[u]+=[v]
	g[v]+=[u]
while sum([len(g[i]) for i in range(n)])>0:
	for i in range(n):
		if len(g[i])==1:
			u=g[i][0]
			g[i].remove(u)
			g[u].remove(i)
			for v in g[u]:
				g[v].remove(u)
				if len(g[v])==0:
					print("First")
					exit()
			g[u]=[]
print("Second")