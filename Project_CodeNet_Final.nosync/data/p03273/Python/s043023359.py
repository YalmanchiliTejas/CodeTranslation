import numpy as np
H,W = list(map(int,input().split()))

A=[]
for h in range(H):
    a = input()
    if '#' in a:
        A.append(list(a))

A=np.array(A).T
A_=[]
for w in range(W):
    a=A[w]
    if '#' in a:
        A_.append(a)
        
A_=np.array(A_).T
for a in A_:
    print(''.join(a))