H,W = map(int,input().split())
grid = []
vissible = []
for i in range(H):
  grid.append(input())
  vissible.append([True for i in range(W)])

cnt = 0
while True:
  flag = True
  for i in range(H):
    tmp = 0
    vis = 0
    for j in range(W):
      if vissible[i][j]:
        vis += 1
      if vissible[i][j] and grid[i][j] == '.':
        tmp += 1
    if vis and tmp == vis:
      for j in range(W):
        vissible[i][j] = False
      flag = False
  for j in range(W):
    tmp = 0
    vis = 0
    for i in range(H):
      if vissible[i][j]:
        vis += 1
      if vissible[i][j] and grid[i][j] == '.':
        tmp += 1
    if vis and tmp == vis:
      for i in range(H):
        vissible[i][j] = False
      flag = False
  if flag:
    break
  if cnt > 10:
    break
  cnt += 1
for i in range(H):
  flag = False
  for j in range(W):
    if vissible[i][j]:
      print(grid[i][j], end='')
      flag = True
  if flag:
    print()