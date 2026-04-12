h,w=map(int,input().split())
s=list(input()for _ in[0]*h)
a=[0]*h
b=[0]*w
for i in range(h):
    f=0
    for j in range(w):f+=s[i][j]=='#'
    a[i]=f>0
for j in range(w):
    f=0
    for i in range(h):f+=s[i][j]=='#'
    b[j]=f>0
for i in range(h):
    if not a[i]:continue
    for j in range(w):
        if b[j]:print(s[i][j],end='')
    print()
