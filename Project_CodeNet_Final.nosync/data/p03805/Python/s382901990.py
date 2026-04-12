n,m=map(int,input().split())
lis=[[0 for i in range(n)] for _ in range(n)]
for i in range(m):
	x,y=map(int,input().split())
	lis[x-1][y-1]=1
	lis[y-1][x-1]=1
s=""
k=[]
import itertools
for i in range(n):
	s+=str(i)
for i in itertools.permutations(s):
	k.append(i)
ans=0
for i in range(len(k)):
	if k[i][0]!="0":
		continue
	for j in range(n-1):
		if lis[int(k[i][j])][int(k[i][j+1])]==0:
			break
		elif j==n-2:
			ans+=1
print(ans)
