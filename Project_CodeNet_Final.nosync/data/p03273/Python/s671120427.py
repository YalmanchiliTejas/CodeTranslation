H, W = map(int, input().split())

black_h = []
black_w = []

a = []
for h in range(H):
  s = input()
  for si, sv in enumerate(list(s)):
    if sv == '#':
      black_h.append(h)
      black_w.append(si)
  a.append(list(s))

ans = []
for h in range(H):
  if h not in black_h:
    continue
  A = []
  for w in range(W):
    if w not in black_w:
      continue
    A.append(a[h][w])
  ans.append(A)
  
for v in ans:
  print(''.join(v))
