N, M = map(int, raw_input().split())
E = {}
for _ in range(M):
	a, b = map(int, raw_input().split())
	if not a in E: E[a] = set()
	if not b in E: E[b] = set()
	E[a].add(b)
	E[b].add(a)

def numPaths(visited_nodes, start_node):
	if len(visited_nodes) == N-1:
		return 1
	sum = 0
	for adj_node in E[start_node]:
		if not adj_node in visited_nodes:
			visited_nodes.add(start_node)
			sum += numPaths(visited_nodes, adj_node)
			visited_nodes.remove(start_node)
	return sum

print numPaths(set(), 1)