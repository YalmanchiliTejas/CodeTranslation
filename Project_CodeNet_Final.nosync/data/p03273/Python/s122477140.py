h,w=map(int,input().split())
a=[list(input()) for j in range(h)]

for p in range(w):
    f=True
    for q in range(h):
        if a[q][p]=="#":f=False
    if f:
        for y in range(h):a[y][p]=""
res=[]
for t in a:
    if t.count(".")+t.count("")!=len(t):res.append(t)
for t in res:
    print("".join(t))