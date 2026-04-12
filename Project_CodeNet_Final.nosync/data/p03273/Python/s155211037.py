h,w=map(int,input().split())
a,c=[],[]
for i in range(h):
    a.append(input())
for i in range(w):
    b=0
    for j in range(h):
        if a[j][i]=='#':
            b=1
    c.append(b)
for i in range(h):
    if a[i]=='.'*w:
        continue
    for j in range(w):
        if c[j]==1:
            print(a[i][j],end='')
    print('')