h,w = map(int,input().split())
a = [list(input()) for i in range(h)  ]
lsti = []
lstj = []

for i in range(h):
    if "#" not in a[i]: lsti.append(i)

for j in range(w):
    for i in range(h):
        if a[i][j] == "#":
            break
    else:
        lstj.append(j)

for i in range(h):
    for j in range(w):
        if i not in lsti and j not in lstj:
            print(a[i][j],end = "")
    else:
        if i not in lsti:
            print("")