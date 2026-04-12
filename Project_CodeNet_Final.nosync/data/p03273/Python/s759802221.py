H, W = map(int, input().split())
a = [list(input()) for i in range(H)]

del_H = []
del_W = []
for i in range(H):
  for j in range(W):
    if a[i][j] == '#':
      break
    if j == W - 1:
      del_H.append(i)
for j in range(W):
  for i in range(H):
    if a[i][j] == '#':
      break
    if i == H - 1:
      del_W.append(j)
for i in range(H):
  if i not in del_H:
    for j in range(W):
      if j not in del_W:
        print(a[i][j], end="")
    print()
