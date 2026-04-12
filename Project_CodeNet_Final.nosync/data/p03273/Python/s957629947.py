H, W = map(int, input().split())
S = [input() for _ in range(H)]
  
flag = True
cols = []
rows= []
  
for i in range(0, H):
  flag = True
  for j in range(0, W):
    if S[i][j] == '#':
      flag = False
  if flag:
    cols.append(i)

for i in range(0, W):
  flag = True
  for j in range(0, H):
    if S[j][i] == '#':
      flag = False
  if flag:
    rows.append(i)
      
for i in range(0, H):
  for j in range(0, W):
    if i not in cols and j not in rows:
      print(S[i][j], end="")
  if i not in cols:
    print()