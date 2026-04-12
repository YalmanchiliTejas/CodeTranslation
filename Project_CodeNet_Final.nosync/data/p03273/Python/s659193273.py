h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
hl=[]
wl=[]
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            hl.append(i)
            wl.append(j)
for i in set(hl):
    for j in set(wl):
        print(a[i][j],end='')
    print()
