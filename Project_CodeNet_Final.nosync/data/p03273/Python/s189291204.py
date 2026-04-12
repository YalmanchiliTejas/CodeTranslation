def resolve():
	h, w = map(int, input().split())
	grid = []
	for _ in range(h):
		grid.append(list(input()))
	for i in range(h):
		removable = True
		for j in range(w):
			if grid[i][j] == '#':
				removable = False
				break
		if removable:
			for j in range(w):
				grid[i][j] = False

	for i in range(w):
		for j in range(h):
			removable = True
			if grid[j][i] == '#':
				removable = False
				break
		if removable:
			for j in range(h):
				grid[j][i] = False
	for r in grid:
		ans = ""
		for el in r:
			if el:
				ans += el
		if ans:
			print(ans)
resolve()