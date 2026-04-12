h,w=map(int,input().split())
l=[]
for i in range(h):
    l.append(list(map(str,input())))

row=[False]*h
col=[False]*w
for i in range(h):
    for k in range(w):
        if l[i][k]=="#":
            row[i]=True
            col[k]=True
for i in range(h):
    if row[i]:
        for k in range(w):
            if col[k]:
                print(l[i][k], end="")
        print("")
