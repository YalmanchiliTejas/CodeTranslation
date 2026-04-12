H, W = map(int,input().split())
grid = [input() for _ in range(H)]

row = [False]*H
col = [False]*W

for i in range(H):
  for j in range(W):
    if grid[i][j] == "#":
      row[i] = True
      col[j] = True

for i in range(H):
  if row[i]:
    for j in range(W):
      if col[j]:
        print(grid[i][j], end="")
    print()