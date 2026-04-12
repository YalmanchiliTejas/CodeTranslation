H,W=map(int,input().split())
a=[list(input()) for i in range(H)]
X=[0 for i in range(W)]
Y=[0 for i in range(H)]
for i in range(H):
    flag=0
    for j in range(W):
        if a[i][j]=="#":
            flag=1
            break
    if flag==0:
        Y[i]=1
for j in range(W):
    flag=0
    for i in range(H):
        if a[i][j]=="#":
            flag=1
            break
    if flag==0:
        X[j]=1
for i in range(H):
    st=""
    if Y[i]==1:
        continue
    for j in range(W):
        if X[j]==0:
            st+=a[i][j]
    print(st)

