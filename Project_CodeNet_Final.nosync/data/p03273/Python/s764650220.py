H, W = map(int, input().split())
A = []
for i in range(H):
  A.append(list(map(str, input().split())))

A_int = []
for a in A:
  temp = []
  for i in range(W):
    if a[0][i] == '.':
      temp.append(0)
    else:
      temp.append(1)
  if sum(temp)>0:
    A_int.append(temp)

import numpy as np
A = np.array(A_int)
del_columns=[]
for i in range(len(np.all(A==0, axis=0))):
  if np.all(A==0, axis=0)[i]==True:
    del_columns.append(i)
A_del = np.delete(A, del_columns, axis=1)

for i in range(A_del.shape[0]):
  ans=""
  for j in range(A_del.shape[1]):
    if A_del[i][j]==0:
      ans += "."
    else:
      ans += "#"
  print(ans)