h,w = list(map(int, input().split()))

board = []
board.append(['.'] * (w+2))
for i in range(h):
    board.append(list('.' + input() + '.'))
board.append(['.'] * (w+2))

for i in range(1,h+1):
    for j in range(1,w+1):
        left = board[i][j-1]
        upper = board[i-1][j]
        if left == '#' and upper == '#':
            print('Impossible')
            exit()
print('Possible')