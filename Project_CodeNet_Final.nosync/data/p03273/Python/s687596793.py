H, W = map(int, input().split())
field = [[i for i in input()] for j in range(H)]

b_rows = []
for row in range(H):
    if field[row].count(".") != W:
        b_rows.append(row)

b_columns = []
for column in range(W):
    memo = []
    for row in range(H):
        memo.append(field[row][column])
    if memo.count(".") != H:
        b_columns.append(column)

for i in b_rows:
    for j in b_columns:
        print(field[i][j], end="")
    print()