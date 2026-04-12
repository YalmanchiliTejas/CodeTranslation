import numpy as np

h, w = map(int,input().split())
grid = np.array([list(input()) for _ in range(h)], dtype="U1") # ここ最大の学びだ

row = []
col = []

for i in range(h):
    if (grid[i] != ".").any():
        row.append(i)

trans_grid = np.transpose(grid)

for i in range(w):
    if (trans_grid[i] != ".").any():
        col.append(i)

G = grid[row][:,col] # ここも学び。colに指定されているとこだけだす　https://qiita.com/supersaiakujin/items/d63c73bb7b5aac43898a

for g in G:
    print("".join(g))