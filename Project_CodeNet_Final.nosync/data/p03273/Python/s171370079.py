H,W=map(int,input().split())
M=[0]*H
for i in range(H):
    M[i]=input()
H_cnt=[0]*H
W_cnt=[0]*W
for i in range(H):
    for j in range(W):
        if M[i][j]=='#':
            H_cnt[i]=1
            W_cnt[j]=1
for i in range(H):
    for j in range(W):
        if W_cnt[j]==1 and H_cnt[i]==1:
            print(M[i][j],end='')
    if H_cnt[i]==1:
        print()