h,w = map(int,input().split())
a = list()

for i in range(h):
  a.append(input())

h_blank = [False]*h
w_blank = [False]*w
for i in range(h):
  blank = True
  for j in range(w):
    if a[i][j] == '#':
      blank = False
      break
  if blank:
    h_blank[i] = True

for i in range(w):
  blank = True
  for j in range(h):
    if a[j][i] == '#':
      blank = False
      break
  if blank:
    w_blank[i] = True

for i in range(h):
  if h_blank[i]:
    continue
  for j in range(w):
    if w_blank[j]:
      continue
    print(a[i][j], end='')
  print('')