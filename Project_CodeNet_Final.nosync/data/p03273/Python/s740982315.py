import numpy as np
H, W = [int(i) for i in input().split()]
ai = [list(input()) for i in range(H)]
arr = np.asarray(ai)
for x in range(H):
  if '#' not in arr[x,:]:
    arr[x,:] = 'a'
for y in range(W):
  if '#' not in arr[:,y]:
    arr[:,y] = 'a'
for x in range(H):
  str = ''
  for y in range(W):
    if arr[x,y] != 'a':
      str += arr[x,y]
    else:
      pass
  if str != '':
    print(str)
  else:
    pass