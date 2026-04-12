H, W = map(int, input().split())
board = [list(input()) for i in range(H)]

skip_col = [False] * W
for i in range(len(board[0])):
    for j in range(H):
        if board[j][i] == '#':
            break
    else:
        skip_col[i] = True

for i in range(H):
    if all([c == '.' for c in board[i]]):
        continue
    for j in range(W):
        if skip_col[j]:
            continue
        print(board[i][j], end='')
    print('')
