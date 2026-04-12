import numpy as np
 
H, W=map(int, input().split())
matrix=np.zeros((H, W))
 
for i in range(H):
  s=input()
  for j in range(W):
    if s[j]=='#':
      matrix[i, j]=1
      
for i in range(H):
  if np.sum(matrix[i, :]==0)==W:
    matrix[i, :]=-1
    
for i in range(W):
  if np.sum(matrix[:, i]<=0)==H:
    matrix[:, i]=-1
    
i=0
for i in range(H):
  if np.sum(matrix[i, :]==-1)==W:
    pass
  else:
    for j in range(W):
      if matrix[i, j]==0:
        print('.', end='')
      elif matrix[i, j]==1:
        print('#', end='')
      else:
        pass
    print()