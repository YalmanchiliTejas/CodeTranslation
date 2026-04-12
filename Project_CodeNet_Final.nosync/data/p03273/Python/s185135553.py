h, w = map(int, input().split())
a=[input() for i in range(h)]
ver=[False]*w
hor=[False]*h

for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            ver[j]=True
            hor[i]=True

for i in range(h):
    if hor[i]:
        for j in range(w):
            if ver[j]==True:
                print(a[i][j],end="")
        print()