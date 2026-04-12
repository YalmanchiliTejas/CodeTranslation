h,w=map(int,input().split())
A=[input() for i in range(h)]
B=[]
for i in range(h):
    if '#' in A[i]:
        B.append(A[i])
def rot(X):
    C=[]
    for l in range(len(X[0])):
        C_row=[]
        for m in X:
            C_row.append(m[l])
        C.append(C_row)
    return C
D=rot(B)
E=[]
for i in range(w):
    if '#' in D[i]:
        E.append(D[i])
F=rot(E)
for f in F:
    print(''.join(f))