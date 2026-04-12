import sys

H, W = map(int, input().split())
a = [line for line in sys.stdin.readlines()]

row = [False] * H
column = [False] * W

for i, temp_row in enumerate(a):
    for j, c in enumerate(temp_row):
        if c == "#":
            row[i] = True
            column[j] = True

for i, exist_row in enumerate(row):
    if not exist_row:
        continue
    for j, exist_column in enumerate(column):
        if exist_column:
            print(a[i][j], end = "")
    print()
