import numpy as np
H, W = map(int, input().split())
a = np.array([list(input()) for _ in range(H)])

row_ind = np.where(np.all(a==['.']*(np.shape(a)[1]) ,axis=1))
a = np.delete(a, row_ind, axis=0)

col_ind = np.where(np.all(a==[['.']]*(np.shape(a)[0]), axis=0))
a = np.delete(a, col_ind, axis=1)

for i in range(np.shape(a)[0]):
    print(''.join(a[i,:]))