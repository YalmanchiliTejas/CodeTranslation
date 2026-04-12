h, w = map(int, input().split())
a = [input() for i in range(h)]
w_row = []
w_column = []
for i in range(h):
  black = False
  for j in range(w):
    if a[i][j] == '#':
      black = True
      break
  if not black:
    w_row.append(i)
for i in range(w):
  black = False
  for j in range(h):
    if a[j][i] == '#':
      black = True
      break
  if not black:
    w_column.append(i)
for i in range(h):
  if i in w_row:
    continue
  s = ''
  for j in range(w):
    if j in w_column:
      continue
    s += a[i][j]
  print(s)
