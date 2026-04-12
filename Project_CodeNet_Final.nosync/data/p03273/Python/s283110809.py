h, w = map(int, input().split())

a = [input() for i in range(h)]

bh = [0] * h
bw = [0] * w

for i in range(h):
  for j in range(w):
    if a[i][j] == '#':
      bh[i] = 1
      bw[j] = 1
      
for i in range(h):
  if bh[i]:
    for j in range(w):
      if bw[j]:
        print(a[i][j], end='')
    print()