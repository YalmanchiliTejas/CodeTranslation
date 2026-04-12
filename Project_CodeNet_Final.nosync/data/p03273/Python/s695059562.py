H,W = map(int,input().split())
a = []
for i in range(H):
    a.append(list(input()))

row = [False for i in range(H)]
col = [False for i in range(W)]

for i in range(H):
    for j in range(W):
        if a[i][j] == "#":
            row[i] = True
            col[j] = True

for i in range(H):
    if row[i] == True:
        for j in range(W):
            if col[j] == True:
                print(a[i][j],end="")
        print()
