from itertools import permutations as P
N, M = map(int, input().split())

web = [set() for _ in range(N)]
for _ in range(M):
	a, b = map(int, input().split())
	web[a-1].add(b-1)
	web[b-1].add(a-1)
way = list(P(range(1, N), N-1))
res = 0
for i in range(len(way)):
	if way[i][0] in web[0]:
		flag = True
		for j in range(1, N-1):
			if way[i][j] not in web[way[i][j-1]]:
				flag = False
				break
		if flag: res += 1

print(res)