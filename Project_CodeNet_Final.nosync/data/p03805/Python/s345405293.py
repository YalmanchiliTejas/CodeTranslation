import sys
sys.setrecursionlimit(10000000)

def dfs(v, visited):
	all_visited = True
	
	for i in range(N):
		if visited[i] == False:
			all_visited = False
	
	if all_visited:
		return 1
	
	ret = 0
	
	for i in range(N):
		if graph[v][i] == False:
			continue
		if visited[i]:
			continue
		
		visited[i] = True
		ret += dfs(i, visited)
		visited[i] = False
	
	return ret

N, M = [int(x) for x in input().split()]
graph = [[False] * N for _ in range(N)]

for i in range(M):
	A, B = [int(x) for x in input().split()]
	graph[A-1][B-1] = graph[B-1][A-1] = True

visited = [False] * N

visited[0] = True
print(dfs(0, visited))