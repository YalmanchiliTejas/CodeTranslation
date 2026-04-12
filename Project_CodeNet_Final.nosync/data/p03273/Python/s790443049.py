### ABC107 B - Grid Compression
h, w = map(int, input().split())
grid = [[x for x in str(input())] for _ in range(h)]

del_h = [False] * h
del_w = [False] * w

for i in range(h):
  if grid[i].count('#') == 0:
    del_h[i] = True

for j in range(w):
  del_w[j] = True
  for i in range(h):
    if grid[i][j] == '#':
      del_w[j] = False
      break

for i in range(h):
  if del_h[i]: continue
  row = ''.join([grid[i][j] for j in range(w) if not del_w[j]])
  print(row)
