h, w = list(map(int, input().split()))
a = [input() for i in range(h)]
x, y = [], []
for i in range(h):
  f = True
  for j in range(w):
    if a[i][j]=="#":
      f = False
  if f:
    y.append(i)
for j in range(w):
  f = True
  for i in range(h):
    if a[i][j]=="#":
      f = False
  if f:
    x.append(j)
for i in range(h):
  if i in y:
    continue
  for j in range(w):
    if j in x:
      continue
    print(a[i][j], end="")
  print()