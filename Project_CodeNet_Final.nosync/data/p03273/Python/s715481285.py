import numpy as np
import sys

buf = sys.stdin.buffer
H,W = map(int,buf.readline().split())

grid = np.frombuffer(buf.read(H*(W+1)), dtype='S1').reshape((H,W+1))
grid = grid[:,:-1]

select_col = (grid == b'#').any(axis = 0)
select_row = (grid == b'#').any(axis = 1)

grid = grid[select_row, :]
grid = grid[:, select_col]
grid = grid.astype(str)

print('\n'.join(''.join(row) for row in grid))
