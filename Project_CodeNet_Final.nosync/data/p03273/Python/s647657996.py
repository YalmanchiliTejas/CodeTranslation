# https://atcoder.jp/contests/abc107/tasks/abc107_b
from copy import deepcopy
h, w = map(int, input().split())
matrix = []
for _ in range(h):
    row = list(input())
    matrix.append(row)

# delete row
rows = []
for i in range(h):
    white = False
    for j in range(w):
        if matrix[i][j] == '#':
            break
    else:
        white = True
    if white:
        rows.append(i)
t = []
for i in range(h):
    if i in rows:
        continue
    t.append(matrix[i])
h -= len(rows)
matrix = t

# delete col
cols = []
for i in range(w):
    white = False
    for j in range(h):
        if matrix[j][i] == '#':
            break
    else:
        white = True
    if white:
        cols.append(i)

t = []
for i in range(h):
    row = []
    for j in range(w):
        if j in cols:
            continue
        row.append(matrix[i][j])
    t.append(row)
w -= len(cols)
matrix = t
for r in matrix:
    print(''.join(r))