H, W=map(int, input().split())
a=[list(input()) for _ in range(H)]
b=[[0 for _ in range(W)] for _ in range(H)]
for i in range(H):
    if '#' in a[i]:
        for j in range(W):
            b[i][j]+=1
for j in range(W):
    if any(a[i][j]=='#' for i in range(H)):
        for k in range(H):
            b[k][j]+=1
for i in range(H):
    for j in range(W):
        if b[i][j]==2:
            print(a[i][j], end='')
    if 2 in b[i]:
        print('')
