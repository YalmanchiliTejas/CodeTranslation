import sys

# A - Shik and Stone
def go(grid, i, j):
	global H
	global W
	global routes

	if i < H and j < W:
		import copy
		c = copy.deepcopy(grid)

		c[i][j] = '#'

		if i == H - 1 and j == W - 1:
			routes.append(c)
		else:
			go(c, i + 1, j)
			go(c, i, j + 1)


def merge_grid(grid):
	s = ''

	for line in grid:
		s += ''.join(line)

	return s


H, W = map(int, input().split())
A = []
grid = []

for _ in range(H):
	A.append(input())
	grid.append(['.'] * W)

routes = []
go(grid, 0, 0)

possibles = set()

for route in routes:
	possibles.add(merge_grid(route))

if merge_grid(A) in possibles:
	print('Possible')
else:
	print('Impossible')