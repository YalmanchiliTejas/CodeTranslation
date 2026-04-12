import numpy as np
H, W = map(int, input().split())
a = np.array([list(input()) for _ in range(H)])
row = np.all(a == '.', axis=0)
col = np.all(a == '.', axis=1)
for i in range(H):
    if col[i]:
        continue
    for j in range(W):
        if row[j]:
            continue
        print(a[i][j], end='')
    print()