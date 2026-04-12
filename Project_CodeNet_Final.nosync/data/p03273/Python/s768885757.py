h,w = map(int, input().split())
a = [list(x for x in input()) for _ in range(h)]
b = []
c = []
for i in range(h):
  if '#' in a[i]:
    continue
  else:
    b.append(i)

for j in range(w):
  for k in range(h):
    if '#' == a[k][j]:
      break
    elif k == h-1:
      c.append(j)

for m in range(h):
  count = 0
  if m in b:
    continue
  for n in range(w):
    if n in c:
      continue
    else:
      count +=1
      print(a[m][n], end='')
    if count == (w-len(c)):
      print()