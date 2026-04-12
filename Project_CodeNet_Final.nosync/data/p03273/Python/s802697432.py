import numpy as np


H, W = map(int, input().split())

A = []

for h in range(H):
    a = list(input())
    if '#' in a:
        A.append(a)

A = np.rot90(np.array(A)).tolist()
B = []

for w in range(len(A)):
    if '#' in A[w]:
        B.append(A[w])


B = np.rot90(np.array(B), 3).tolist()

for b in B:
    print(str.join('', b))
