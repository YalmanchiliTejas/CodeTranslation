h,w = map(int,input().split())
a=["" for _ in range(h)]
for i in range(h):
    a[i]=list(input())
for i in range(h):
    key=0
    for j in range(w):
        if a[i][j]=="#":
            key=1
    if key==0:
        for j in range(w):
            a[i][j]=""
for i in range(w):
    key=0
    for j in range(h):
        if a[j][i]=="#":
            key=1
    if key==0:
        for j in range(h):
            a[j][i]=""
for i in range(h):
    if a[i]!=["" for _ in range(w)]:
        print(''.join(a[i]))
