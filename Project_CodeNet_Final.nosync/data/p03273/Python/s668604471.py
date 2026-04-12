import numpy as np
h, w = map(int, input().split())
a = [[c for c in input()] for i in range(h)]
a = np.array(a)
colums = []
rows = []
for i in range(h):
    if not np.all(a[i] == '.'):
        colums.append(i)
for i in range(w):
    if not np.all(a[:, i] == '.'):
        rows.append(i)
a = a[colums]
for l in a[:, rows]:
    print(''.join(l))