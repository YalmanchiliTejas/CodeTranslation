import numpy as np
H, W = map(int, input().split())
grid = []
for _ in range(H):
    a = [i for i in input()]
    if "#" in a:
        grid.append(a)
grid = np.array(grid)
grid_T = grid.T
ans = []
for i in range(W):
    if "#" in grid_T[i]:
        ans.append(grid_T[i])
ans = np.array(ans).T
for i in range(ans.shape[0]):
    print("".join(ans[i]))