h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]

row = []
col = []
for i in range(h):
  if a[i].count(".") != w: row.append(i)
for i in range(w):
  t = 0
  for j in range(h):
    if a[j][i] == ".": t+=1
  if t != h: col.append(i)

for i in row:
  ans = ""
  for j in col:
    ans += a[i][j]
  print(ans)