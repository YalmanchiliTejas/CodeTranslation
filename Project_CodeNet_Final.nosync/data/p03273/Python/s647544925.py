import numpy as np
H, W, *A = open(0).read().split()
H = int(H)
W = int(W)

A = list(map(lambda x: list(map(int, x.replace(".", "0").replace("#", "1"))), A))
A = np.array(A)
r = np.sum(A, axis = 0)
c = np.sum(A, axis = 1)

A = A[c != 0, :]
A = A[:, r != 0]

res = list(map(lambda x: "".join(list(map(str, list(x)))).replace("0", ".").replace("1", "#"), list(A)))
for x in res:
  print(x)

