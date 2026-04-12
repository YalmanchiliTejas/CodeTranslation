from itertools import permutations

N,M = map(int,input().split(' '))

nodes = list(range(N))
paths = [[0] * N for i in range(N)]

for i in range(M):
	a,b = map(int,input().split(' '))
	paths[a-1][b-1] = 1
	paths[b-1][a-1] = 1

ans = 0

for p in permutations(nodes[1:],len(nodes)-1):
	cnt = 0
	for j in range(len(p)):
		if(j == 0):
			nb = 0
			nn = p[j]
		else:
			nb = p[j-1]
			nn = p[j]
		if(paths[nb][nn] == 1):
			cnt = cnt + 1
		else:
			break
		if(cnt == len(p)):
			ans = ans + 1
print(ans)