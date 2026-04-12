H, W = map(int, input().split())
A = [input() for i in range(H)]

visited = [[False]*W for i in range(H)]
visited[0][0] = True
d = [[0, 0, -1, -1]]
while d:
  x, y, px, py = d.pop()
  num = 0
  flag = False
  for dx, dy in [[1, 0], [0, 1], [-1, 0], [0, -1]]:
    if 0<=x+dx<H and 0<=y+dy<W and [x+dx, y+dy]!=[px, py] and A[x+dx][y+dy]=='#' and not visited[x+dx][y+dy]:
      visited[x+dx][y+dy] = True
      num += 1
      d.append([x+dx, y+dy, x, y])
      if dx < 0 or dy < 0:
        flag = True
  if (num >= 2) or flag:
    print('Impossible')
    quit()

print('Possible')