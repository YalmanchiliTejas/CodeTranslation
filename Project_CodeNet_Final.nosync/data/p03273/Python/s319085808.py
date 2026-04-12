h,w=map(int,input().split())
a=['']*h
for i in range(h):
    a[i]=input()
r=[0]*h
c=[0]*w

for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            r[i]=1
            c[j]=1
for i in range(h):
    if r[i]:
        for j in range(w):
            if c[j]:
                print(a[i][j],end='')
        print()