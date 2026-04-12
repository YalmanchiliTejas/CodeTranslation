H,W = map(int,input().split(" "))
table = []
for i in range(H):
  table.append(list(input()))
row = [False]*H
col = [False]*W
for i in range(H):
  for j in range(W):
    if table[i][j] == "#":
      row[i] = True
      col[j] = True
for i in range(H):
  if row[i]:
    for j in range(W):
      if col[j]:
        print(table[i][j],end='')
    print()