# coding: utf-8
import numpy as np
H, W = map(int, input().split())
maze = []
#入力の時点で行で削れるとことは削る
for _ in range(H):
    s = list(input())
    if s != ["."]*W:
        maze.append(s)
maze = np.array(maze)
#列で削れるところを削る
undels = []
for i in range(maze.shape[1]):
    if sum(maze[:, i] == ".") != maze.shape[0]:
        undels.append(i)
ans = maze[:, undels]
for i in range(ans.shape[0]):
    print(*ans[i], sep="")