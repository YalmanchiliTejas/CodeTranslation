H,W=map(int,input().split())
A=[]
for i in range(H):
    a=input()
    A.append(a)
B=[]
for i in range(H):
    if A[i]!='.'*W:
        B.append(A[i])
C=[]
for k in range(W):
    c=[]
    for i in range(len(B)):
        c.append(B[i][k])
    C.append(c)

D=[]
for i in range(W):
    if C[i]!=['.']*len(B):
        D.append(C[i])
E=[]
for k in range(len(B)):
    e=[]
    for i in range(len(D)):
        e.append(D[i][k])
    E.append(e)

for h in range(len(E)):
    print(''.join(E[h]))

