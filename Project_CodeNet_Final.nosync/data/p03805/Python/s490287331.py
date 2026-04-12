import itertools

N, M = map(int, input().split())
c = [[False] * N for i in range(N)]
for i in range(M):
	a, b = map(int, input().split())
	c[a - 1][b - 1] = True
	c[b - 1][a - 1] = True
ans, d = 0, [i for i in range(N)]
for i in itertools.permutations(d[1:]):
	e, f = True, list(i)
	f.insert(0, d[0])
	for j in range(N - 1):
		if not c[f[j]][f[j + 1]]:
			e = False
			break
	if e:
		ans += 1
print(ans)