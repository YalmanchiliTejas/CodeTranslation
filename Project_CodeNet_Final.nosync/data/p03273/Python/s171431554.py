H, W = map(int, input().split())
grid = [list(input()) for i in range(H)]

rout = [False]*H
for i in range(H):
    for j in range(W):
        if grid[i][j] == '#':
            rout[i] = True
            break

cout = [False]*W
for i in range(W):
    for j in range(H):
        if grid[j][i] == '#':
            cout[i] = True
            break

for i in range(H):
    for j in range(W):
        if rout[i] and cout[j]:
            print(grid[i][j], end="")
    if rout[i]:
        print("")
