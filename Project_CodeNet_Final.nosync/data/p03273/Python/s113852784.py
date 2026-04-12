h, w = map(int, input().split())
a = [input() for _ in range(h)]

row = []
column = []

for i in range(h):
    flag = 1
    first = "."
    for j in range(w):
        if a[i][j] != first:
            flag = 0
    if flag == 0:
        row.append(i)

for j in range(w):
    flag = 1
    first = "."
    for i in range(h):
        if a[i][j] != first:
            flag = 0
    if flag == 0:
        column.append(j)


for i in row:
    output = ""
    for j in column:
        output += a[i][j]
    if output != "":
        print(output)