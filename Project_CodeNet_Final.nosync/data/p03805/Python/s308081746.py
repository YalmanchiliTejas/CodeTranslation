import copy

N, M = map(int,input().split())
E = [list(map(int, input().split())) for _ in range(M)]



def dfs(flg, E, i):
	q = []
	for e in E:
		if e[0] == i:
			if flg[e[1]-1] == 0:
				q.append(e[1])
		if e[1] == i:
			if flg[e[0]-1] == 0:
				q.append(e[0])
	if len(q) == 0:
		if flg.count(0) == 0:
			return 1
		else:
			return 0

	ans = 0
	for n in q:
		temp = copy.deepcopy(flg)
		temp[n-1] = 1
		ans += dfs(temp, E, n)

	return ans

flg = [0 for _ in range(N)]
flg[0] = 1
print(dfs(flg, E, 1))