h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]

row = []
col = []
for i in range(h):
  if a[i].count("#") == 0: row.append(i)
    
for i in range(w):
  for j in range(h):
    if a[j][i] == "#": break
  else: col.append(i)

for i in range(h):
  if i in row: continue
  ans = ""
  for j in range(w):
    if j in col: continue
    ans += a[i][j]
  print(ans)