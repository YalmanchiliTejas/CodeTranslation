row_num, col_num = (int(i) for i in input().split())
matrix = [ list(input()) for i in range(row_num)]
transpose_matrix = []
for i in range(col_num):
    transpose_matrix.append([])
    for j in range(row_num):
        transpose_matrix[i].append(matrix[j][i])

empty_rows = []
# row check
for i,line in enumerate(matrix):
    if '#' in line:
        continue
    empty_rows.append(i)
empty_cols = []
# col check
for i,line in enumerate(transpose_matrix):
    if '#' in line:
        continue
    empty_cols.append(i)

for i in range(row_num):
    if i in empty_rows:
        continue
    for j in range(col_num):
        if j in empty_cols:
            continue
        print(matrix[i][j],end="")
    print()
        