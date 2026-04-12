h,w=map(int,input().split())
board = []
for _ in range(h):
    row = input()
    if '#' in row:
        board.append(row)
result = [''] * len(board)
for i in range(w):
    if any(row[i] == '#' for row in board):
        result = [result[j] + board[j][i] for j in range(len(board))]
for rrow in result:
    print(rrow)