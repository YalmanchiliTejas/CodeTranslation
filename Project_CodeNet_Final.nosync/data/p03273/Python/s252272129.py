H,W =map(int,input().split())

a=[list(input()) for i in range(H)]
l_idx=[]
c_idx=[]
for i in range(H):
    for j in range(W):
        if a[i][j]=="#":
            l_idx.append(i)
            c_idx.append(j)

for i in range(W-1,-1,-1):
    if not i in c_idx:
        for j in range(H):
            a[j].pop(i)

for i in range(H):
    if i in l_idx:
        print("".join(a[i]))