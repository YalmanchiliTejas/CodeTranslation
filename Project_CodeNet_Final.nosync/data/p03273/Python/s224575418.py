H, W = map(int,input().split())
a = []

for i in range(H):
    a.append(input())

row = [i for i in range(H)]
column = [i for i in range(W)]

row_delete = []
column_delete = []

for i in range(H):
    flag_delete = True
    for j in range(W):
        if a[i][j] == "#":
            flag_delete = False
            break
    if flag_delete == True:
        row_delete.append(i)

for i in range(W):
    flag_delete = True
    for j in range(H):
        if a[j][i] == "#":
            flag_delete = False
            break
    if flag_delete == True:
        column_delete.append(i)

# 行
for i in row_delete:
    row.remove(i)
# 列
for i in column_delete:
    column.remove(i)

ans = [["" for _ in range(len(column))] for _ in range(len(row))]

count_row = 0
for i in row:
    count_column = 0
    for j in column:
        ans[count_row][count_column] = a[i][j]
        count_column += 1
    count_row += 1

for i in range(len(ans)):
    print("".join(ans[i]))