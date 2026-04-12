import numpy as np
h, w = map(int, input().split())
board = [list(str(input())) for _ in range(h)]
for j in range(2):
    board = [i for i in board if i.count('#') != 0]
    board = np.array(board)
    board = board.T
    board = board.tolist()
for i in board:
    print(*i, sep='')