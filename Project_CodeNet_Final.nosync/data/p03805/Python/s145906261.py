import itertools

N, M = map(int, input().split())
E = [[] for _ in range(N)]

for _ in range(M):
	ta, tb = map(int, input().split())
	E[ta-1].append(tb-1)
	E[tb-1].append(ta-1)

ans = 0

for p in itertools.permutations(range(1,N)):
	p = [0] + list(p)
	cond = 1
	for i in range(N-1):
		if p[i+1] not in E[p[i]]:
			cond = 0
	if cond:
		ans += 1


print(ans)
