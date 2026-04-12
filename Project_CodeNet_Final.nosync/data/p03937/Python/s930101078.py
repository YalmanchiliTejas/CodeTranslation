import numpy as np
h, w = map(int, input().split())
A = [input() for _ in range(h)]
B = np.empty((h+1, w+1), dtype=str)
for i in range(h):
  for j in range(w):
    B[i, j] = A[i][j]

x = y = 0
B[y, x] = '.'
while x != w-1 or y != h-1:
  if B[y, x+1] == B[y+1, x] == '#':
    print('Impossible')
    exit()
  elif B[y, x+1] == '#':
    x += 1
  else:
    y += 1
  B[y, x] = '.'

if np.any(B == '#'):
  print('Impossible')
else:
  print('Possible')