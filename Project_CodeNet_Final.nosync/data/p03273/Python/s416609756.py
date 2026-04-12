h, w = map(int, input().split())
g = ['']*h
for i in range(h):
  g[i] = input()

row = [False] * h
col = [False] * w
for i in range(h):
  for j in range(w):
    if g[i][j] == '#':
      row[i] = True
      col[j] = True

for i in range(h):
  if row[i]:
    for j in range(w):
      if col[j]:
        print(g[i][j], end='')
    print()
