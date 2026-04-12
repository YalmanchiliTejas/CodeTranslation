H, W = map(int, input().split())

board = list()
line = list()

for x in range(0, H):
    word = input()
    for y in word:
        line.append(y)
    if '#' in line:
        board.append(line)
    line = list()

H = len(board)

goodx = [True]*W

judge = True

for a in range(0, W):
    for b in range(0, H):
        if board[b][a] == '#':
            judge = False
    if judge:
        goodx[a] = False
    judge = True

for a in range(0, H):
    for b in range(0, W):
        if goodx[b]:
            print(board[a][b], end='')
    print('')
