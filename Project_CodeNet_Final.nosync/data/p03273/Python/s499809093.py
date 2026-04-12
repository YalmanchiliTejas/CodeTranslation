H,W=map(int,input().split())
mas=[list(s for s in input()) for _ in range(H)]
height=[]
width=[]
for i in range(H):
    for j in range(W):
        if mas[i][j]=='#':
            height.append(i)
            width.append(j)

height=set(height)
height=list(height)
width=set(width)
width=list(width)
for a in height:
    ans=[]
    for b in width:
        ans.append(mas[a][b])
    print(*ans,sep='')