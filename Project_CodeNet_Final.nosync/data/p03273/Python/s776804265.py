H, W = map(int, input().split())
a = [input() for _ in range(H)]
row = [False] * H
col = [False] * W
for i in range(len(row)):
  for j in range(len(col)):
    if a[i][j] == '#':
      row[i] = col[j] = True

for i in range(len(row)):
  if row[i]:
    for j in range(len(col)):
      if col[j]:
        print(a[i][j], end = '')
    print()