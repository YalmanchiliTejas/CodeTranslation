import itertools

n, m = map(int, input().split())

lst = [[0 for _ in range(n)] for _ in range(n)]

for i in range(m):
	a, b = map(int, input().split())
	a, b = a - 1, b -1
	lst[a][b] = 1
	lst[b][a] = 1

l = list(range(n))

cnt = 0
for v in itertools.permutations(l):
	flg = True
	if v[0] == 0:
		for i in range(n-1):
			x, y = v[i], v[i + 1]
			if lst[x][y] == 0: # pathがなければ
				flg = False
		if flg:
			cnt += 1

print(cnt)