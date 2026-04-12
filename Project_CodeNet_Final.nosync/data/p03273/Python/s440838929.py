h, w = map(int, input().split())
a = [input() for _ in range(h)]

has_black_rows = [False for _ in range(h)]
has_black_columns = [False for _ in range(w)]

for i in range(h):
    for j in range(w):
        if a[i][j] in '#':
            has_black_rows[i] = True
            has_black_columns[j] = True

for i in range(h):
    if has_black_rows[i]:
        for j in range(w):
            if has_black_columns[j]:
                print(a[i][j], end='')
        print()
