from sys import stdin
import numpy as np

H, W = map(int,input().split())
board = [[str(c) for c in l.strip()] for l in stdin]
np_board = np.array(board)
np_board = np_board[:, np.any(np_board == "#", axis=0)]
np_board = np_board[np.any(np_board == "#", axis=1), :]

for i in range(np_board.shape[0]):
  for j in range(np_board.shape[1]):
    print(np_board[i][j], end="")
  print("")
    

