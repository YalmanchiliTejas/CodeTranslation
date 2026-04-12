h,w=map(int,input().split())
g=[list(input()) for _ in range(h)]
c=0
for i in range(h):
    for j in range(w):
        if g[i][j]=="#":
            c+=1
if c==h+w-1:
    print("Possible")
else:
    print("Impossible")
