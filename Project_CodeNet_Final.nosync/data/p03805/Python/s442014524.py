N, M = map(int, input().split())
AB = [list(map(int, input().split())) for _ in range(M)]

edges = [set() for _ in range(N + 1)]
for a, b in AB:
	edges[a] |= {b}
	edges[b] |= {a}

count = 0
def dfs(current, visited):
	global count
	if N == len(visited):
		count += 1
		return
	for _next in edges[current]:
		if _next not in visited:
			dfs(_next, visited | {_next})

dfs(1, {1})

print(count)
