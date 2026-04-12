import numpy as np

H,W = map(int,input().split())
grid = []

for i in range(H):
  line = list(input())
  grid.append(line)

mod_grid = []
for i in range(H):
  if '#' in grid[i]:
    mod_grid.append(grid[i])
    
mod_grid = np.array(mod_grid).T
mod_grid2 = []
for i in range(W):
  if '#' in mod_grid[i]:
    mod_grid2.append(mod_grid[i])
    
mod_grid2 = np.array(mod_grid2).T
for i in range(mod_grid.shape[1]):
  if '#' in mod_grid2[i]:
    print(''.join(mod_grid2[i]))

  