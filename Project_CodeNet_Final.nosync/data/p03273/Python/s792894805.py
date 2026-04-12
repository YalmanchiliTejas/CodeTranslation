h, w = map(int, input().split())

board = []
for i in range(h):
    board.append(input())

hm = []
for i in range(h):
    if board[i] == '.' * w:
        hm.append(i)

wm = []
for i in range(w):
    for j in range(h):
        if board[j][i] != '.':
            break
        if j == h-1:
            wm.append(i)


for i in range(h):
    for j in range(w):
        if i not in hm and j not in wm:
            print(board[i][j], end='')
    if i not in hm:
        print()

