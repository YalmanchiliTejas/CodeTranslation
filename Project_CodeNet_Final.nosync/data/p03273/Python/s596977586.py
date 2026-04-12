H, W = map(int,input().split())
A = [input() for k in range(H)]
B = []
for k in range(len(A)):
    if A[k] != "."*W:
        B.append(A[k])

C = []
for k in range(len(B[0])):
    T = ""
    for l in range(len(B)):
        T += B[l][k]
    C.append(T)

D = []
for k in range(len(C)):
    if C[k] != "."*len(C[0]):
        D.append(C[k])

for k in range(len(D[0])):
    T = ""
    for l in range(len(D)):
        T += D[l][k]
    print(T)


