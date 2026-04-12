n, m = map(int, input().split(" "))
ab = [list(map(int, input().split(" "))) for _ in range(m)]

l = [set() for _ in range(n)]
for a_i, b_i in ab:
	l[a_i-1].add(b_i-1)
	l[b_i-1].add(a_i-1)

# print(l)

def dfs(num, visited=set()):
	visited = visited | {num}
	can_moves = l[num] - visited
	# print(num, visited, can_moves)
	if not can_moves:
		# print(visited, n)
		return (len(visited) == n)

	sum_num = 0
	for can_move in can_moves:
		sum_num += dfs(can_move, visited)
	return sum_num

print(dfs(0))