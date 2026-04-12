n, m = map(int, input().split())
arr = list(list(input()) for _ in range(n))
rmv_row = [1] * n
rmv_col = [1] * m
for i in range(n):
    for j in range(m):
        if arr[i][j] == '#':
            rmv_row[i] = 0
            rmv_col[j] = 0
for i in range(n):
    if rmv_row[i] == 1:
        continue
    for j in range(m):
        if rmv_col[j] == 1:
            continue
        print(arr[i][j], end='')
    print()
