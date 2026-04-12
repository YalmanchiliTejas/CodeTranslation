H,W = map(int,input().split())
t = []
Hcut = []
Wcut = []
count = 0
for i in range(H):
  t.append(input())
  
#削除するべき行の検出  
for i in range(H):
  for j in range(W):
    if t[i][j] == "#":
      count += 1
      break
  if count == 0:
    Hcut.append(i)
  count = 0
  
#削除するべき列の検出
for i in range(W):
  for j in range(H):
    if t[j][i] == "#":
      count += 1
      break
  if count == 0:
    Wcut.append(i)
  count = 0

#出力
for i in range(H):
  judge = 0
  for j in range(W):
    if i in Hcut or j in Wcut:
      continue
    else:
      print(t[i][j],end="")
      judge = 1
  if judge == 1:
    print()
  
  