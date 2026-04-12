h, w = map(int, input().split())
grid = []
for i in range(h):
  s = input()
  if '#' in s:
    grid.append(list(s))
h = len(grid)

for j in range(w)[::-1]:
  skip = False
  for i in range(h):
    if grid[i][j] == '#':
      skip = True
      break
  if not skip:
    for i in range(h):
      grid[i][j] = ''

for row in grid:
  print(''.join(row))