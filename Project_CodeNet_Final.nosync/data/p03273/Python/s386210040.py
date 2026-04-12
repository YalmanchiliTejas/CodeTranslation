H,W = map(int,input().split())
a = []
row = []
for i in range(H):
    tmp = list(input())
    if tmp.count(".") == len(tmp):
        row.append(i)
    a.append(tmp)
column = []
for i in range(W):
    count = 0
    for j in range(H):
        if a[j][i] == ".":
            count += 1
    if count == H:
        column.append(i)

for i in range(H):
    if i not in row:
        for j in range(W):
            if j not in column:
                print(a[i][j],end="")
        print("")