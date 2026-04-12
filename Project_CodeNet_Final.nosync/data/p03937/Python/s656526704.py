H, W = map(int, input().split())
L = [input() for _ in range(H)]

count = 0
for i in range(H):
  for j in range(W):
    if L[i][j] == '#':
      count += 1
      
if count == W + H - 1:
  print('Possible')
else:
  print('Impossible')