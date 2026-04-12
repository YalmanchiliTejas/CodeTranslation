H,W = map(int,input().split())
a = [input() for i in range(H)]

H_idx=[]
for i in range(H):
    count = 0
    for j in range(W):
        if a[i][j]=='.':
            count +=1
    if count != W:
        H_idx.append(i)

W_idx=[]
for i in range(W):
    count = 0
    for j in range(H):
        if a[j][i]=='.':
            count +=1
    if count != H:
        W_idx.append(i)

for i in H_idx:
    ans = ''
    for j in W_idx:
        ans +=a[i][j]
    print(ans)