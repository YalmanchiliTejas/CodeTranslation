# recursively find all one-stroke paths
def findPaths(start, used):
	# if all vertices used, return 1 path found
	if len(used) == n:
		return 1

	# traverse all connections to unused vertices
	tot = 0
	for v in conn[start]:
		if v not in used:
			used.append(v)
			tot += findPaths(v, used)
			used.pop()

	# return total number of one-stroke paths found
	return tot

# get number of vertices N and edges M
n, m = map(int, raw_input().split())

# build a dict where key is start vertex and value is list of connected vertices
conn = {}
for i in range(m):
	a, b = map(int, raw_input().split())
	if a in conn:
		conn[a].append(b)
	else:
		conn[a] = [b]
	if b in conn:
		conn[b].append(a)
	else:
		conn[b] = [a]

# recursively start at vertex 1 with corresponding visited queue and find all one-stroke paths
print (findPaths(1, [1]))