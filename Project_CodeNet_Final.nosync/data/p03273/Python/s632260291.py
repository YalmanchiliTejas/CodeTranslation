# B - Grid Compression
H, W = map(int, input().split())
grid = []

for i in range(H):
	a = input()
	
	if '#' in a:
		grid.append(a)

ans = [''] * len(grid)

for i in range(W):
	count = 0
	
	for j in range(len(grid)):
		if grid[j][i] == '#':
			count += 1
	
	if count > 0:
		for j in range(len(grid)):
			ans[j] += grid[j][i]

for a in ans:
	print(a)