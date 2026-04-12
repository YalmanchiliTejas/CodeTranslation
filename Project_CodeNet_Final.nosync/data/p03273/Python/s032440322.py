H,W=map(int,input().split())
grid=[input() for i in range(H)]
h=[]
w=[]
for i in range(H):
    for j in range(W):
        if grid[i][j]=='#':
            h.append(i)
            w.append(j)
h=list(set(h))
w=list(set(w))
for i in h:
    p=''
    for j in w:
        p+=grid[i][j]
    print(p)