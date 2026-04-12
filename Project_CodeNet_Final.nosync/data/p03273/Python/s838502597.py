import numpy as np
H, W = map(int, input().split())
I = [input() for i in range(H)]
I_n = [list(j) for j in I if '#' in j]
h = np.array(I_n)
n = 0
for k in range (W):
  if '#' not in h[:, n]:
    h = np.delete(h, n, 1)
  else:
    n += 1
H, W = h.shape
for l in range(H):
  A = ""
  for m in range(W):
    A += h[l, m]
  print(A)