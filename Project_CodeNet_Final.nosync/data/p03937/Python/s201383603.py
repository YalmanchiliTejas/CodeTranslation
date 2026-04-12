# coding: utf-8
import numpy as np
H, W = map(int, input().split())
board = []
tb = [[False] * W] * H
tb = np.array(tb)
cnt = 0
for i in range(H):
    tmp = list(input())
    for j in range(W):
        if tmp[j] == "#":
            cnt += 1
            if "s" not in globals():
                s = [i, j]
    board.append(tmp[:])
board = np.array(board)
tb[s[0], s[1]] = True
for i in range(H):
    for j in range(s[1], W):
        if board[i][j] == "#":
            s[1] = j
            tb[s[0], s[1]] = True
    if s[0] < H - 1:
        s[0] += 1
    if board[s[0], s[1]] == "#":
        tb[s[0], s[1]] = True
    else:
        break
print("Possible" if cnt == np.sum(tb) else "Impossible")