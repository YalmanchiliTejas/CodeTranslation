H,W = list(map(int,input().split()))
board =[[' ' for i in range(W)] for j in range(H)]
for i in range(H):
    line = input()
    for j in range(W):
        board[i][j] = line[j]

count = 0
index = 0
while count < H:
    line = board[index]
    isWhite = True
    for i in range(len(line)):
        if line[i] == '#':
            isWhite = False
    if isWhite:
        board.pop(index)
    else:
        index += 1
    count += 1

count = 0
index = 0
while count < W:
    isWhite = True
    for i in range(len(board)):
        if board[i][index] == '#':
            isWhite = False
    if isWhite:
        for j in range(len(board)):
            board[j].pop(index)
    else:
        index += 1
    count += 1

for i in range(len(board)):
    line = board[i]
    lineString = ''
    for j in range(len(line)):
        lineString += line[j]
    print(lineString)