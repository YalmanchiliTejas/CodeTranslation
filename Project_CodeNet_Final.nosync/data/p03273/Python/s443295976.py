[H,W] = list(map(int,input().split()))

a = []
for i in range(H):
    a.append(list(input()))

line = [0]*H
colu = [0]*W
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            line[i]=1
            colu[j]=1

ans=[]
for i in range(H):
    dammy=[]
    for j in range(W):
        if line[i]==1 and colu[j]==1 :
            dammy.append(a[i][j])
    if dammy!=[]:
        ans.append(dammy)

for i in range(len(ans)):
    print(''.join(ans[i]))