from itertools import permutations

n,m = map(int,input().split())
D = [[0]*n for i in range(n)]
for i in range(m):
	a,b = map(int,input().split())
	D[a-1][b-1] = 1
	D[b-1][a-1] = 1
cnt = 0
for a in permutations(range(n)):
	if a[0] != 0:
		break
	tmp = 1
	for i in range(n-1):
		tmp = tmp * D[a[i]][a[i+1]]
	cnt += tmp
print(cnt)