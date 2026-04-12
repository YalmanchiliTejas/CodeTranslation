H, W = map(int, input().split())
a = [[]]
for _ in range(H):
    temp = ["#"] + list(input())
    a.append(temp)

removed_rows = []
removed_cols = []
for row in range(1, H+1):
    is_all_dot = 1
    for col in range(1, W+1):
        if a[row][col] == "#":
            is_all_dot = 0
    if is_all_dot:
        removed_rows.append(row)
for col in range(1, W+1):
    is_all_dot = 1
    for row in range(1, H+1):
        if a[row][col] == "#":
            is_all_dot = 0
    if is_all_dot:
        removed_cols.append(col)

for row in range(1, H+1):
    if row in removed_rows:
        continue
    for removed_col in removed_cols:
        a[row][removed_col] = ""
    ans = "".join(a[row][1:])
    print(ans)