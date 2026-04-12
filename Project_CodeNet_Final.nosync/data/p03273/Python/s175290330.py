h,w=map(int,input().split())
l=[list(input()) for i in range(h)]
hs=set()
ws=set()
for i in range(h):
    for j in range(w):
        if l[i][j]=="#":
            hs.add(i)
            ws.add(j)
for i in hs:
    for j in ws:
        print(l[i][j],end="")
    print()