h,w = map(int, input().split())
g = []
for i in range(h):
  c = input()
  if '#' not in c:
    continue
  g.append(c)
h = len(g)
memo = []
for i in range(w):
  f = 1
  for j in range(h):
    if g[j][i] == '#':
      f = 0
  if f:
    memo.append(i)
for j in range(h):
  print(''.join([g[j][i] for i in range(w) if i not in memo]))