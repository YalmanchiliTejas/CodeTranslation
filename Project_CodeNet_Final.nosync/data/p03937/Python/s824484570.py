import numpy as np

# 盤面の受け取り
H,W = map(int,input().split())
board = [[] for _ in range(H)]
for i in range(H):
    board[i] = list(input())

board = np.array(board)

minnum = W
maxnum = 0
for row in board[::-1]:
    S = "".join(row)
    left = S.find("#")
    right = len(S) - 1 - S[::-1].find("#")
    if right > minnum:
        print("Impossible")
        exit()
    minnum = left
    maxnum = right

board = board.T

minnum = H
maxnum = 0
for row in board[::-1]:
    S = "".join(row)
    left = S.find("#")
    right = len(S) - 1 - S[::-1].find("#")
    if right > minnum:
        print("Impossible")
        exit()
    minnum = left
    maxnum = right

print("Possible")
