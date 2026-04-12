from itertools import permutations as perm
n,m = map(int,input().split())
coor = [[False]*n for _ in range(n)]
for i in range(m):
	a,b = map(int,input().split())
	a,b = a-1,b-1
	coor[a][b] = True
	coor[b][a] = True
ll = list(range(n))
res = 0
for l in perm(ll):
	if l[0]!=0:
		continue
	for (i,j) in zip(l,l[1:]):
		if not coor[i][j]:
			break
	else:
		res += 1
print(res)