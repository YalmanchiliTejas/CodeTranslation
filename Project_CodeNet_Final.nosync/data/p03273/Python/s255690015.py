h,w=map(int,input().split())
l=[list(input()) for i in range(h)]
tate=[False]*h
yoko=[False]*w
for i in range(h):
    for j in range(w):
        if l[i][j]=="#":
            tate[i]=True
            yoko[j]=True
for i in range(h):
    if tate[i]:
        for j in range(w):
            if yoko[j]:
                print(l[i][j],end="")
        print()