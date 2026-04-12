H,W = list(map(int,input().split()))
grid = [input() for i in range(H)]

for h in range(H):
  for w in range(W):
    flag1 = 0
    flag2 = 0
    if grid[h][w] == "#":
      if 0 <= h-1 < H:
        if grid[h-1][w] == "#":
          flag1 += 1
      if 0 <= w-1 < W:
        if grid[h][w-1] == "#":
          flag1 += 1
      if 0 <= h+1 < H:
        if grid[h+1][w] == "#":
          flag2 += 1
      if 0 <= w+1 < W:
        if grid[h][w+1] == "#":
          flag2 += 1

      if (h == 0 and w == 0):
        if flag1 == 0 and flag2 == 1:
          continue
        else:
          print("Impossible")
          exit()
      if (h == H-1 and w == W-1):
        if flag1 == 1 and flag2 == 0:
          continue
        else:
          print("Impossible")
          exit()
      else:
        if flag1 == 1 and flag2 == 1:
          continue
        else:
          print("Impossible")
          exit()
else:
  print("Possible")