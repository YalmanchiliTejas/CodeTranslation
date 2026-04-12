import numpy as np

n, m = map(int, input().split())
data = []
for _ in range(n):
    d = []
    for s in input():
        if s == '#':
            d.append(1)
        else:
            d.append(0)
    data.append(d)
data = np.array(data)
col = np.sum(data, axis=1)
row = np.sum(data, axis=0)

for i in range(n):
    if col[i] == 0: continue
    for j in range(m):
        if row[j]==0: continue
        s = '#' if data[i][j] == 1 else '.'
        print(s, end='')
    print()