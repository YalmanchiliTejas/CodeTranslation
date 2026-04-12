h,w = map(int,input().split())
a = []
for i in range(h):
    a.append(input())
hh = [False]*h
ww = [False]*w
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            hh[i]=True
            ww[j]=True
for i in range(h):
    if hh[i]:
        for j in range(w):
            if ww[j]:
                print(a[i][j],end="")
        print()
