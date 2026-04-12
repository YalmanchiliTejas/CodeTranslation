H, W = map(int, input().split())
board = [input() for i in range(H)]
used  = [[False]*W for i in range(H)]

used[0][0] = True
q = [(0, 0)]

while len(q) > 0:
    y, x = q[0]
    q = q[1:]
    if x+1 < W and board[y][x+1]=='#' and not used[y][x+1]:
        used[y][x+1] = True;
        q.append((y, x+1))
    elif y+1 < H and board[y+1][x]=='#' and not used[y+1][x]:
        used[y+1][x] = True;
        q.append((y+1, x))

ans = True
for i in range(H):
    for j in range(W):
        if board[i][j] == '#':
            ans = ans and used[i][j]

print("Possible") if ans else print("Impossible")
