import numpy as np

n, m = list(map(int, input().split()))

board = []
for i in range(n):
    l = list(input())
    board.append(l)
board = np.array(board, dtype='unicode')

tmp = []
for i in range(board.shape[0]):
    if sum(board[i, :] == '.') == board.shape[1]:
        tmp.append(i)
board = np.delete(board, tmp, axis=0)

tmp = []
for i in range(board.shape[1]):
    if sum(board[:, i] == '.') == board.shape[0]:
        tmp.append(i)
board = np.delete(board, tmp, axis=1)

for i in range(board.shape[0]):
    for j in range(board.shape[1]):
        print(board[i, j], end='')
    print()

