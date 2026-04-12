import numpy as np

h, w = [int(x) for x in input().split()]
board = [input() for i in range(h)]
dellist = []
for i in range(h):
    if '#' not in board[i]:
        dellist.append(i)
for i in sorted(dellist, reverse=True):
    del board[i]

board = [list(x) for x in board]
board_t = np.array(board).T.tolist()
dellist2 = []
for i in range(w):
    if '#' not in board_t[i]:
        dellist2.append(i)
for i in sorted(dellist2, reverse=True):
    del board_t[i]

board_t_t = np.array(board_t).T

[print(''.join(x)) for x in board_t_t]