H, W = map(int, input().split())
grid = []
for i in range(H):
  line = input()
  for i in range(len(line)):
    if line[i] == '#':
      grid.append(line)
      break
gridans = [[''] for i in range(len(grid))]
for i in range(W):
  flag = 0
  for j in range(len(grid)):
    if grid[j][i] == '#':
      flag = 1
  if flag == 1:
    for j in range(len(grid)):
      gridans[j][0] += grid[j][i]
for i in range(len(gridans)):
  print(gridans[i][0])
