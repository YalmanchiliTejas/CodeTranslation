from sys import stdin
h,w = [int(x) for x in stdin.readline().rstrip().split()]
data = [stdin.readline().rstrip() for _ in range(h)]
row=[False]*h
col=[False]*w
for i,r in enumerate(data):
    for j,c in enumerate(r):
        if c=='#':
            row[i]=True
            col[j]=True
for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(data[i][j],end='')
        print()