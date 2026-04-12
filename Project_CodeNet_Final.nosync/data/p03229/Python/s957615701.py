import numpy as np
N=int(input())
A=np.empty(N)
for i in range(N):
    A[i]=int(input())
m = np.median(A)
dA = np.abs(A-m)
sdA=np.sort(dA)
D = int(sdA[0:2].sum() + sdA[2:].sum()*2)
print(D)