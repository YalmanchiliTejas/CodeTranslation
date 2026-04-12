h,w=map(int,input().split())
a=[list(input()) for _ in range(h)]
row=[]
col=[]
for i in range(h):
    if "#" in a[i][:]:
        row.append(i)
b=[list(x) for x in zip(*a)]
for j in range(w):
    if "#" in b[:][j]:
        col.append(j)
for i in row:
    for j in col:
        print(a[i][j],end="")
    print("")