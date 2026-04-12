H, W = map(int, input().split())
a = [input() for _ in range(H)]

clm = [True] * H
for hi in range(H):
  ai = a[hi]
  for c in ai:
    if c == '#':
      clm[hi] = False
      break
      
row = [True] * W
for wi in range(W):
  for ci in range(H):
    if a[ci][wi] == '#':
      row[wi] = False
      break
      
for hi in range(H):
  if clm[hi] == True:
    continue
  ans = ''
  ai = a[hi]
  for wi in range(W):
    if row[wi] == True:
      continue
    ans += ai[wi]
  print(ans)
