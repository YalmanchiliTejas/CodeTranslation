import numpy as np
H,W = map(int,input().split())
grid = []
ans = []
for i in range(H):
    h = list(input())
    if "#" in h:
        grid.append(h)
grid = np.array(grid)
grid = grid.T
for i in range(len(grid)):
    w = grid[i]
    if "#" in w:
        ans.append(w)
ans = np.array(ans).T
for i in ans:
    print("".join(i))
