h,w=map(int,input().split())
A=[list(input()) for i in range(h)]
B=[]
C=[]
for i in range(h):
    if (set(A[i]))!={'.'}:
        B.append(A[i])
B=list(map(list, zip(*B)))
h_=len(B)
for i in range(h_):
    if set(B[i])!={'.'}:
        C.append(B[i])
C=list(map(list, zip(*C)))
h__=len(C)
for i in range(h__):
    print(''.join(map(str,C[i])))