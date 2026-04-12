h,w = (int(i) for i in input().split())
a = [input() for _ in range(h)]

tate, yoko = [], []
for i in range(h):
  if any([s == '#' for s in a[i]]):
    tate.append(i)
for i in range(w):
  if any(a[j][i] == '#' for j in range(h)):
    yoko.append(i)

for i in tate:
  for j in yoko:
    print(a[i][j], end='')
  print('')