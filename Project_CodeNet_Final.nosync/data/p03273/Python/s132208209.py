import numpy as np

H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]

ret = []
for r in grid:
    if any(x == '#' for x in r):
        ret.append(r)
grid = np.array(ret).T.tolist()

ret = []
for r in grid:
    if any(x == '#' for x in r):
        ret.append(r)

grid = np.array(ret).T.tolist()

for r in grid:
    print(*r, sep='')
