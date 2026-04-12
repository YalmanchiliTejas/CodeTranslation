M =[]
H,W = map(int, input().split())  
tate=[False]*H
yoko=[False]*W
for i in range(H):
    M.append(list(input()))

for i in range(H):
    for j in range(W):
        if M[i][j]=='#':
            tate[i]=True
            yoko[j]=True

for i in range(H):
    if tate[i]:
        out = ''
        for j in range(W):
            if yoko[j]:
                out = out + M[i][j]
        print(out)



