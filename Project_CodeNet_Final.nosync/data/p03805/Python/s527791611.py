def bfs(g, n):
	tovisit = []
	for i in range(0, n):
		tovisit.append(i)
	queue = []
	tovisit.remove(0)
	queue.append([0, tovisit])
	cnt = 0

	while queue != []:
		status = queue.pop(0)
		now = status[0]
		currenttovisit = status[1]
		if currenttovisit == []: cnt = cnt + 1
		else:
			for i in range(0, n):
				newtovisit = []
				for j in range(0, len(currenttovisit)):
					newtovisit.append(currenttovisit[j])
				if i in currenttovisit and graph[now][i]:
					newtovisit.remove(i)
					queue.append([i, newtovisit])
	return cnt

N, M = map(int, raw_input().split())
graph = []
for i in range(0, N):
	arrow = []
	for j in range(0, N):
		arrow.append(False)
	graph.append(arrow)

for i in range(0, M):
	a, b = map(int, raw_input().split())
	graph[a-1][b-1] = True
	graph[b-1][a-1] = True

print bfs(graph, N)