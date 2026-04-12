h,w=map(int,input().split())
a=list(list(input()) for _ in range(h))
for i in range(h):
    for j in range(w):
        if a[i][j]=='.': a[i][j]=0
        elif a[i][j]=='#': a[i][j]=1
for i in range(h):
    if sum(a[i])==0: a[i]=[]
a=[x for x in a if x]
h=len(a)
b=[row for row in zip(*a)]
for i in range(w):
    if sum(b[i])==0: b[i]=[]
b=[x for x in b if x]
w=len(b)
a=[list(row) for row in zip(*b)]
for i in range(h):
    for j in range(w):
        if a[i][j]==0: a[i][j]='.'
        elif a[i][j]==1: a[i][j]='#'
for row in a: print(''.join(row))