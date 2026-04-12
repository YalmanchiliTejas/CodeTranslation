import numpy as np

H, W = map(int, input().split())
A = np.array([list(input()) for h in range(H)])

def delete_rows(A):
  del_list = []
  for i, a in enumerate(A):
    if (a == '.').all():
      del_list.append(i)
  return np.delete(A, del_list, axis=0)


A = delete_rows(delete_rows(A).T).T
for a in A:
  print(''.join(a))