h,w=[int(i) for i in input().split()]
a=[]
row=[]
col=[]
for i in range(h):
    a.append(input())
for i in range(h):
    row.append(False)
for i in range(w):
    col.append(False)

for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            row[i]=True
            col[j]=True

for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(a[i][j],end="")
        print("\n")
