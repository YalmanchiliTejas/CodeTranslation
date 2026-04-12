h, w=map(int, input().split())
a=[""]*h
for i in range(h):
    a[i]=input()

row=[0]*h
col=[0]*w

for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            row[i]=1
            col[j]=1

for i in range(h):
    if row[i]==1:
        for j in range(w):
            if col[j]==1:
                print(a[i][j], end='')

        print()