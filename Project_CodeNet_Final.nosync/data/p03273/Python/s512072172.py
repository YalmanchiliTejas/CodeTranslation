h,w = map(int,input().split())
board = []
checkColumn = [False]*h
checkRow = [False]*w
for i in range(h):
    board.append(input())

for i in range(h):
        for j in range(w):
            if board[i][j] == "#":
                checkColumn[i] = True
                checkRow[j] = True
for i in range(h):
    if checkColumn[i]:
        for j in range(w):
            if checkRow[j]:
                print(board[i][j],end="")
        print()