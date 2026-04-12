H,W = map(int,input().split())
L = ['']*H
for i in range(H):
  L[i] = input()
row = [False]*H
col = [False]*W
for i in range(H):
  for j in range(W):
    if L[i][j] == '#':
      row[i] = True
      col[j] = True
for i in range(H):
  if row[i] == True:
    for j in range(W):
      if col[j] == True:
        print(L[i][j],end = '')
    print()