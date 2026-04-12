import numpy as np
H, W = map(int, input().split())
grid = np.array([list(input()) for _ in range(H)], dtype="U1")

row = []
col = []
for i in range(H):
    if (grid[i] != ".").any():
        row.append(i)

trans_grid = np.transpose(grid)
for i in range(W):
    if (trans_grid[i] != ".").any():
        col.append(i)


G = grid[row][:, col]
for g in G:
    print("".join(g))