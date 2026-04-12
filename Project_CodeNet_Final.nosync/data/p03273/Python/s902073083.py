import numpy as np
H, W = map(int, input().split())
grid = np.array([], dtype=np.int)
for i in range(H):
    grid = np.append(grid, np.array([c=="." for c in input()]))

grid = grid.reshape(H,W)
row_test = np.where(np.sum(grid, axis=1)==W)
col_test = np.where(np.sum(grid, axis=0)==H)

grid = np.delete(grid, row_test[0], axis=0)
grid = np.delete(grid, col_test[0], axis=1)

for r in grid:
    res = ''
    for v in r:
        if v == 1:
            res += '.'
        else:
            res += '#'
    print(res)