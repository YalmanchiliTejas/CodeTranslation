H,W=map(int,input().split())
A=[input() for i in range(H)]
tate=[0]*H
yoko=[0]*W
for i in range(W):
    for j in range(H):
        if A[j][i]=="#":
            tate[j]=1
            yoko[i]=1
ans=[]
for j in range(H):
    if tate[j]==0:
        continue
    a=''
    for i in range(W):
        if yoko[i]==0:
            continue
        a+=A[j][i]
    ans.append(a)
for a in ans:
    print(a)