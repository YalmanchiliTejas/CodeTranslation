H,W=map(int,input().split())
A=[input() for i in range(H)]

#'#'が入っている行および列を列挙する
Tate=[0]*H
Yoko=[0]*W
for i in range(H):
    for j in range(W):
        if A[i][j]=='#':
            Tate[i]+=1
            Yoko[j]+=1

ans=['']*H
for i in range(H):
    for j in range(W):
        if Tate[i]*Yoko[j]>0:
            ans[i]+=A[i][j]

for i in ans:
    if i!='':
        print(i)