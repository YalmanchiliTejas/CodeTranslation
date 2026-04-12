H, M = map(int, input().split())
matrix = []
for i in range(H):
    matrix.append([_ for _ in list(map(str, input()))])

bad_row = set()
bad_column = set()
for i in range(H):
    if all([x == '.' for x in matrix[i]]):
        bad_row.add(i)

for j in range(M):
    tmp = [matrix[i][j] for i in range(H)]
    if all([x == '.' for x in tmp]):
        bad_column.add(j)

for i in range(H):
    for j in range(M):
        if i not in bad_row:
            if j not in bad_column:
                print(matrix[i][j], end='')
    if i not in bad_row:
        print('')
