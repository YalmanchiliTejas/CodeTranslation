h, w = map(int, input().split())
m = [list(input()) for _ in range(h)]

row_idx = []
for idx, row in enumerate(m):
    if not row.count('#'):
        row_idx.append(idx)

col_idx = []
for idx, col in enumerate(zip(*m)):
    if not col.count('#'):
        col_idx.append(idx)

for i, row in enumerate(m):
    if i in row_idx:
        continue
    else:
        for idx in col_idx[::-1]:
            row.pop(idx)
        print(*row, sep='')
