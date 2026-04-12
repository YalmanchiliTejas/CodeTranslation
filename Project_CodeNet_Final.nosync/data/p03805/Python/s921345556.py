N, M = map(int, raw_input().split())
graph = []
for i in range(0, N):
	lst = []
	for j in range(0, N):
		lst.append(False)
	graph.append(lst)
for i in range(0, M):
	a, b = map(int, raw_input().split())
	graph[a-1][b-1] = True
	graph[b-1][a-1] = True
memo = []
for i in range(0, N):
	memo.append(True)
queue = [[0, memo]]
cnt = 0
while queue != []:
	now = queue.pop(0)
	newmemo = []
	for i in range(0, N):
		if i == now[0]: newmemo.append(False)
		else: newmemo.append(now[1][i])
	if True not in newmemo: cnt += 1
	else:
		for i in range(0, N):
			if graph[now[0]][i] and newmemo[i]:
				queue.append([i, newmemo])
print cnt