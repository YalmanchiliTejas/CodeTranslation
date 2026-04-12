H, W = map(int, input().split())
grid = []

for _ in range(H):
  x = input()
  if x != "."*W:
    grid.append(x)

h = len(grid)
Flag = [True]*W

for j in range(W):
  if all(grid[i][j] == "." for i in range(h)):
    Flag[j] = False

for i in range(h):
  print("".join([grid[i][j] for j in range(W) if Flag[j]]))