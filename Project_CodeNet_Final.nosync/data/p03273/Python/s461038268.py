H,W = list(map(int,input().split()))
import numpy as np
A = np.zeros([H,W])
ans = np.zeros([H,W]).astype(np.unicode)
for i in range(H):
    ans[i,:] = [x for x in input()]
    A[i,:] = [1 if x=='#' else 0 for x in ans[i,:]]

rw = np.all(A == 0, axis = 1)
cl = np.all(A == 0, axis = 0)

ans = ans[~rw,:]
ans = ans[:,~cl]
for i in range(ans.shape[0]):
    print("".join(ans[i,:]))