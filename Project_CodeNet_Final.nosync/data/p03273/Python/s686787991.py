import numpy as np

h, w = map(int, input().split())
al = list(list(input()) for _ in range(h))
al_n = np.array(al)
row = [0]*w
col = [0]*h
for i in range(h):
    for j in range(w):
        if al_n[i][j] == '.':
            row[j] += 1
            col[i] += 1
row_ = []
col_ = []
for i in range(w):
    if row[i] == h:
        row_.append(i)

for j in range(h):
    if col[j] == w:
        col_.append(j)

if len(col_) > 0:
    al_n = np.delete(al_n, col_, axis=0)

if len(row_) > 0:
    al_n = np.delete(al_n, row_, axis=1)

for a in al_n:
    print(*a, sep='')