H,W = map(int,input().split())
L = []
for i in range(H):
  L.append(list(input()))
cnt = 0
for j in range(H):
  for k in range(W):
    if L[j][k] == '#':
      cnt += 1
if cnt == H+W-1:
  print('Possible')
else:
  print('Impossible')