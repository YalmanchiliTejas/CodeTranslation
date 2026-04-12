H, W =list(map(int, input().split()))
grid = [ list(input()) for _ in range(H)]

deleted_w = []
for i in range(H):
  if(all(j == "." for j in grid[i])):
    deleted_w.append(i)

deleted_h = []
for i in range(W):
  line = [ grid[k][i] for k in range(H)]
  if(all(j == "." for j in line)):
    deleted_h.append(i)

for i in range(H):
  if(i in deleted_w):
    continue
  for j in range(W):
    if(j in deleted_h):
      continue
    else:
      print(grid[i][j], end="")
  print("")