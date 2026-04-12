H,W=list(map(int,input().split()))
A=[]
for h in range(H):
    A.append(list(input()))

B=[]
for h in range(H):
    if '#' in A[h]:
        B.append(A[h])

C=[]
for w in range(W):
    C.append([])

for h in range(len(B)):
    for w in range(W):
        C[w].append(B[h][w])

D=[]
for h in range(len(C)):
    if '#' in C[h]:
        D.append(C[h])

E=[]
for w in range(W):
    E.append([])

for h in range(len(D)):
    for w in range(len(D[h])):
        E[w].append(D[h][w])

for h in range(len(E)):
    print("".join(E[h]))