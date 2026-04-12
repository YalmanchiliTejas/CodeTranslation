h, w = (int(i) for i in input().split())
a = [input() for i in range(h)]

black_mark_row = set()
black_mark_col = set()
for i in range(h):
    for j in range(w):
        if a[i][j] == "#":
            black_mark_row.add(i)
            black_mark_col.add(j)

for i in range(h):
    flag_line = False
    for j in range(w):
        if i in black_mark_row and j in black_mark_col:
            print(a[i][j],sep="",end="")
            flag_line = True
    if flag_line:
        print()