H,W = map(int,input().split())
A = [input() for _ in range(H)]

for i in range(H+W-1):
  if i < W:
    x = i
    y = 0
  else:
    x = W-1
    y = i-x
  cnt = 0
  while(x >= 0 and y < H):
    if A[y][x] == '#':
      cnt += 1
    #print(x,y,cnt)
    if cnt > 1:
      print('Impossible')
      exit()
    x -= 1
    y += 1
print('Possible')