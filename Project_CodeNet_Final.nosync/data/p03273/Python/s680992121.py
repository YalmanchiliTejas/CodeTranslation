H, W = map(int, input().split())
a = [None]*H
b = [[1 for j in range(W)] for i in range(H)]
delete = 1
for i in range(0, H):
  a[i] = input()
for i in range(0, H):
  for j in range(0, W):
    if a[i][j] != ".":
      delete = 0
      break
  if delete == 1:
    for j in range(0, W):
      b[i][j] = 0
  else:
    delete = 1
for j in range(0, W):
  for i in range(0, H):
    if a[i][j] != ".":
      delete = 0
      break
  if delete == 1:
    for i in range(0, H):
      b[i][j] = 0
  else:
    delete = 1
new_line = 0
for i in range(0, H):
  for j in range(0, W):
    if b[i][j] == 1:
      print(a[i][j], end = '')
      new_line = 1
  if new_line == 1:
    print(" ")
    new_line = 0
      
