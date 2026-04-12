h, w = map(int, input().split())
grid = []
for i in range(h):
  temp = list(input())
  if not temp.count('.') == w:
    grid.append(temp)

remove = []

for i in range(w):
  count = 0
  for j in range(len(grid)):
    if grid[j][i] == '.':
      count += 1
  
  if count == len(grid):
    remove.append(i)

for i in range(len(grid)):
  ans = ''
  for j in range(len(grid[0])):
    if not j in remove:
      ans += grid[i][j]
  
  print(ans)