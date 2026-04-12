h,w = map(int, input().split())
a = [list(input()) for _ in range(h)]
dh = []
dw = []
for i in range(h):
  if not('#' in a[i]):
    dh.append(i)
for j in range(w):
  cal = ''
  for k in range(h):
    cal += a[k][j]
    if k == h-1 and not('#' in cal):
      dw.append(j)

for hl in sorted(dh, reverse=True):
  a.pop(hl)

for wl in sorted(dw, reverse=True):
  for i in range(h-len(dh)):
    a[i].pop(wl)

for i in range(len(a)):
  print(''.join(a[i]))