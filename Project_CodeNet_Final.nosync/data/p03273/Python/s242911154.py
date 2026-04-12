import numpy as np
H,W=map(int, input().split())
A=[]

for h in range(H):
    a=list(input())
    A.append(a)

A=np.array(A)
hs=[]
ws=[]

for i in range(H):
    if (A[i,:]=="#").sum()==0:
        hs.append(i)
for i in range(W):
    if (A[:,i]=="#").sum()==0:
        ws.append(i)

for h in range(H):
    if h not in hs:
        L=[]
        for w in range(W):
            if w not in ws:
                L.append(A[h,w])
        print("".join(L))


