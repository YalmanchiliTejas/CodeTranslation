import numpy as np
H,W = map(int,input().split(' '))
X = []
for i in range(H):
  X.append(list(input()))
X = np.array(X)
a = X[:,~np.all(X == '.',axis=0)]
b = a[~np.all(a == '.',axis=1),:]
for i in b:
  print(''.join(i))