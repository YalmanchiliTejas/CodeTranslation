n,m=map(int,input().split())
c=[[] for i in range(n)]
for i in range(m):
	a,b=map(int,input().split())
	c[a-1].append(b-1)
	c[b-1].append(a-1)
cnt=[0]
def dfs(z,s):
	z[s]=1
	if sum(z)==n:
		cnt[0]+=1
	else:
		for i in c[s]:
			if z[i]==0:
				dfs(z[:i]+[1]+z[i+1:],i)
dfs([0]*n,0)
print(cnt[0])