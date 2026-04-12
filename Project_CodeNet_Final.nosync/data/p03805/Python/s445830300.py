from itertools import permutations
n,m=map(int,input().split())
con=[[0]*n for _ in range(n)]
for _ in range(m):
	a,b=map(int,input().split())
	con[a-1][b-1]=con[b-1][a-1]=1
ans=0
for p in permutations(range(n)):
	if p[0]!=0:
		continue
	if all(con[x][y] for x,y in zip(p,p[1:])):
		ans+=1
print(ans)