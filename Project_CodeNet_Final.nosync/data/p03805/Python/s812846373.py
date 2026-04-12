N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]

g = [[] for _ in range(N)]
for a, b in AB:
	a, b = a - 1, b - 1
	g[a] += [b]
	g[b] += [a]

def dfs(v, visited):
	#print(visited)
	if v in visited:
		return False
	if N - 1 == len(visited):
		return True
	count = 0
	for n in g[v]:
		count += dfs(n, visited | {v})
	return count

print(dfs(0, set()))
