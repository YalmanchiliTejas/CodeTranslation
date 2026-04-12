H, W = map(int, input().split())
board = [input() for i in range(H)]
row, col = [], []
for i in range(H):
    c = sum(board[i][j] == '.' for j in range(W))
    row.append(c != W)
for j in range(W):
    c = sum(board[i][j] == '.' for i in range(H))
    col.append(c != H)
for i in range(H):
    for j in range(W):
        if row[i] and col[j]: print(board[i][j], end='')
    if row[i]: print()
        
