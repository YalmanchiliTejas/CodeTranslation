import copy


N, M = list(map(int,input().split()))
graph = [dict() for i in range(N)]
for i in range(N):
	graph[i]["edge"] = []
for i in range(M):
	a, b = list(map(int, input().split()))
	graph[a - 1]["edge"].append(b - 1)
	graph[b - 1]["edge"].append(a - 1)

def pow(N):
	ans = 1
	for i in range(N):
		ans *= i + 1
	return  ans

total = 0
for i in range(pow(N - 1)):
	node = [a+1 for a in range(N - 1)]
	num = i
	zyun = [0]
	for j in range(N - 1, 0 , -1):
		mod = num % j
		num -= num % j
		num = num//j
		zyun.append(copy.deepcopy(node[mod]))
		del node[mod]
	judge = 1
	for loc in range(N - 1):
		if not zyun[loc + 1] in graph[zyun[loc]]["edge"]:
			judge = 0
	total += judge

print(total)