h,w = map(int, input().split())
flg = 0
a = []
for i in range(h):
  s = input()
  if '#' in s:
    a.append(s)
  else:
    flg += 1
h -= flg
res = ['']*h
for i in range(w):
  flg = 0
  for j in range(h):
    if a[j][i] == '#':
      flg = 1
  if flg == 1:
    for j in range(h):
      res[j] += a[j][i]
for i in range(h):
  print(res[i])