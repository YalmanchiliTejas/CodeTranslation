h, w = map(int, input().split())
a = []
for _ in range(h):
  t = list(input())
  if t.count('.') != w:
    a.append(t)
i = 0
while True:
  if i >= len(a[0]):break
  for t in a:
    if t[i] != '.':
      i += 1
      break
  else:
    for j in range(len(a)):
      del a[j][i]
for t in a:
  print(''.join(t))