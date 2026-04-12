H,W=map(int,input().split())
a=[]
for i in range(H):
    a.append(input())

tate=[[False]*W for i in range(H)]
yoko=[[False]*W for i in range(H)]

for i in range(H):
    if('#' in a[i]):
        for j in range(W):
            yoko[i][j]=True
for j in range(W):
    for i in range(H):
        if(a[i][j]=='#'):
            for k in range(H):
                tate[k][j]=True
            continue
for i in range(H):
    for j in range(W):
        if(tate[i][j] and yoko[i][j]):
            print(a[i][j],end='')
    if(yoko[i]!=[False]*W):
        print()