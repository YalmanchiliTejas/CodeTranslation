inputs = [s.strip() for s in open(0).readlines()]
import numpy as np
class Grid():
    def __init__(self, grid, w=0, h=0, function=lambda x: x):
        self.w = w = w if w else len(grid[0])
        self.h = h = h if h else len(grid)
        dtype = type(function(grid[0][0]))
        self.grid = np.empty((h, w), dtype=dtype)
        for i, rows in zip(range(h), grid):
            for j, val in zip(range(w), rows):
                self.grid[i][j] = function(val)
    
    def is_valid_x(self, x):
        return 0 <= x < self.w
    def is_valid_y(self, y):
        return 0 <= y < self.h
    def is_valid_xy(self, x, y):
        return self.is_valid_x(x) and self.is_valid_y(y) 
    
    def __iter__(self):
        return iter(self.grid)
    def __repr__(self):
        return '\n'.join([' '.join(map(str, rows)) for rows in self.grid])
    def __getitem__(self, x):
        return self.grid[x]
    def __setitem__(self, x, val):
        self.grid[x] = val

h, w = map(int, inputs[0].split())
grid = Grid([s.strip() for s in inputs[1:]]).grid
grid = grid[:, ~np.all(grid == '.', axis=0)]
grid = grid[~np.all(grid == '.', axis=1), :]
print(*[''.join(map(str, row)) for row in grid], sep='\n')