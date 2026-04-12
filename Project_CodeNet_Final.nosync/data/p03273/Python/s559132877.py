h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
a2=[k for k in a if k!=["." for j in range(w)]]
h=len(a2)
count=[True for j in range(w)]
for j in range(w):
    res=True
    for i in range(h):
        if a2[i][j]=="#":
            res=False
            break
    if res:
        count[j]=False
a3=[[a2[i][j] for j in range(w) if count[j]] for i in range(h)]
for i in range(h):
    print("".join(a3[i]))
