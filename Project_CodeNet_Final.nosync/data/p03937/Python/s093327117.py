H,W = map(int,input().split())
GRID = [list(input()) for _ in range(H)]

def dfs(h,w,c):
  if h == H - 1 and w == W - 1:
    return c + 1

  if H - 1 < h or W -1 < w:
    return 0
  
  if GRID[h][w] != "#":
    return 0
  
  
  right = dfs(h+1,w,c+1)
  down = dfs(h,w+1,c+1)

  return max(right,down)

NUM = sum([GRID[x].count("#") for x in range(H)])

n = dfs(0,0,0)

if n == NUM:
  print("Possible")
else:
  print("Impossible")



