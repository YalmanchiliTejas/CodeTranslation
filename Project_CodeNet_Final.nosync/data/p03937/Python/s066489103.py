h, w =map(int, input().split())
grid = [None]*h
count = -1
for i in range(h):
  grid[i] = input()
  count += grid[i].count("#")

x, y = 0, 0

while True:
  if x == h-1 and y == w-1:
    if count == 0:
      print("Possible")
    else:
      print("Impossible")
    break
  elif x == h-1:
    if grid[x][y+1] == ".":
      print("Impossible")
      break
    y += 1
    count -= 1
  elif y == w-1:
    if grid[x+1][y] == ".":
      print("Impossible")
      break
    x += 1
    count -= 1
  else:
    if grid[x+1][y] == grid[x][y+1]:
      print("Impossible")
      break
    if grid[x+1][y] == "#":
      x += 1
    else:
      y += 1
    count -= 1