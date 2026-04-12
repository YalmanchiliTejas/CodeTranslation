H, W = map(int, input().split())
a = [input() for _ in range(H)]

row = []
for i in a:
    if i == '.' * W:
        continue
    row.append(i)

column = []
for i in range(W):
    for j in range(len(row)):
        if row[j][i] == '#':
            column.append(i)
            break

for i in range(len(row)):
    for j in column:
        print(row[i][j], end="")
    print('\n')