h,w = map(int,input().split())
fi = [input() for _ in range(h)]
row = [False]*h
col = [False]*w
for i in range(h):
    for j in range(w):
        if fi[i][j]=='#':
            row[i]=True
            col[j]=True
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(fi[i][j],end='')
        print()