[H,W] = list(map(int,input().split()))
A = [input() for i in range(H)]
row = []
col = []
for i in range(H):
  all_white = True
  for j in range(W):
    if A[i][j] == "#":
      all_white = False
  if all_white:
    row.append(i)
for j in range(W):
  all_white = True
  for i in range(H):
    if A[i][j] == "#":
      all_white = False
  if all_white:
    col.append(j)
for i in range(H):
  if i in row:
    continue
  for j in range(W):
    if j in col:
      continue
    print(A[i][j],end="")
  print()
