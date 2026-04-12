H,W=map(int,input().split())
A=['']*H
for i in range(H):
    A[i]=input()
#print(A)
gyou=[False]*H
retu=[False]*W
for i in range(H):
    for j in range(W):
        if A[i][j]=="#":
            gyou[i]=True
            retu[j]=True
for i in range(H):
    if gyou[i]:
        for j in range(W):
            if retu[j]:
                print(A[i][j],end='')
        print()