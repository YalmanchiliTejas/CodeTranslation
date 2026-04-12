height, width = map(int, input().split())
lis = [[0 for i in range(width)] for i in range(height)]
for i in range(height):
    lis[i] = input()

blank_rows = []
for row in range(height):
    if not "#" in lis[row]:
        blank_rows.append(row)

blank_cols = []
for col in range(width):
    flag = 1
    for row in range(height):
        if "#" == lis[row][col]:
            flag = 0
            break
    if flag:
        blank_cols.append(col)

for row in range(height):
    out = ""
    if not row in blank_rows:
        for col in range(width):
            if not col in blank_cols:
                out += lis[row][col]
    if not out == "":
	    print(out)