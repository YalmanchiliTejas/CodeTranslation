import numpy as np


H, W = map(int, input().split())
lt = []

for i in range(H):
  lt += [list(input())]

  
def show(mat_):
  ptn = "%s" * mat_.shape[1]
  for row in mat_:
    print(ptn % tuple(row))
    
mat = np.array(lt)

mat = mat[:, ~np.all(mat==".", axis=0)]
mat = mat[~np.all(mat==".", axis=1), :]
show(mat)
