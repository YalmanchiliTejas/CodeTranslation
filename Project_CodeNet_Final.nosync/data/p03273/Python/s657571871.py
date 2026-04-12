import numpy as np
H, W = list(map(int, input().split()))

a = np.array([list(input()) for i in range(H)])

at = np.all(a == '.', axis = 1)
for i in reversed(range(len(at))):
  if at[i]:
    a = np.delete(a, i, 0)

at = np.all(a == '.', axis = 0)
for i in reversed(range(len(at))):
  if at[i]:
    a = np.delete(a, i, 1)
for i in a:
  print(''.join(i))