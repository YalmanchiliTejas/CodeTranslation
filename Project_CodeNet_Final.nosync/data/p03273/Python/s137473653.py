import numpy as np
H, W = map(int, raw_input().split())
grids = []
for i in xrange(H):
  grids.append(raw_input())
  
grid_num = []
for grid in grids:
  grid_num.append(map(lambda x: 1 if x == '#' else 0, grid))
  
grid_num = np.array(grid_num)

comp_grid_num = []
for w in xrange(W):
  if grid_num[:, w].any():
    comp_grid_num.append(grid_num[:, w])

comp_grid_num = np.array(comp_grid_num)
comp_grid = ""
for h in xrange(H):
  if comp_grid_num[:, h].any():
    comp_grid += "".join(map(lambda x: '#' if x else '.', comp_grid_num[:, h])) + "\n"
    
print comp_grid
    