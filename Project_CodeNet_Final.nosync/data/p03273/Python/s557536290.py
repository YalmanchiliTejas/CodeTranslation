H,W = map(int,input().split())
h = [0]*H
w = [0]*W
l = [list(input()) for i in range(H)]
for i in range(H):
    if all([i=='.' for i in l[i][:]]):
        h[i]=1
lt = list(zip(*l))
for j in range(W):
    if all([j=='.' for j in lt[j][:]]):
        w[j]=1
for i in range(H):
    for j in range(W):
        if h[i]==0 and w[j]==0:
            print(l[i][j],end='')
    if h[i]==0:
        print()