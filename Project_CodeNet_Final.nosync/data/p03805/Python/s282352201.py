from itertools import permutations
n,m=map(int,input().split())
G=[[0]*n for i in range(n)]
for i in range(m):
	a,b=map(int,input().split())
	G[a-1][b-1]=G[b-1][a-1]=1
l=[i+1 for i in range(n-1)]
c=0
for v in permutations(l,n-1):
	L=[0]+[i for i in v]
	if all([G[L[i]][L[i+1]]==1 for i in range(n-1)]):
		c+=1
print(c)