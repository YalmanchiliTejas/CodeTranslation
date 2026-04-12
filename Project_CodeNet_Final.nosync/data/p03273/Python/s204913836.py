h,w = map(int,input().split())
a = [input() for i in range(h)]
col = [0]*h
row = [0]*w
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            col[i] = 1
            row[j] = 1
for i in range(h):
    ans=""
    for j in range(w):
        if col[i] == 1 and row[j] == 1:
            ans+=a[i][j]
    if ans!="":
        print(ans)