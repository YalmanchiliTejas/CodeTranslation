H, W = map(int, input().split())
A = []
b = ['.' for i in range(W)]
for i in range(H):
  a = list(input())
  if a != b:
    A.append(a)
m = len(A)
import numpy as np
A = np.array(A).T.tolist()
d = ['.' for i in range(m)]
C = []
for i in range(W):
  c = A[i]
  if c != d:
    C.append(c)
    
C = np.array(C).T.tolist()
n = len(C)
for i in range(n):
  ans="".join(C[i])
  print(ans)