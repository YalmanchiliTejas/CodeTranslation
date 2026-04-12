import numpy as np

h, w = map(int, input().split())

board = np.array([list(input()) for i in range(h)])

t_h = []
t_w = []
for i in range(h):
    if np.count_nonzero(board[i] == ".") != w:
        t_h.append(i)
for i in range(w):
    if np.count_nonzero(board[:,i] == ".") != h:
        t_w.append(i)

for y in t_h:
    for x in t_w:
        print(board[y][x],end="")
    print()
