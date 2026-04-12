H, W = map(int, input().split())
maze = [input() for _ in range(H)]

index_h = []
index_w = []

for i in range(H):
    for j in range(W):
        if maze[i][j] == '#':
            break
        if j == W - 1:
            index_h.append(i)

for j in range(W):
    for i in range(H):
        if maze[i][j] == '#':
            break
        if i == H - 1:
            index_w.append(j)


for i in range(H):
    flag = True
    for j in range(W):
        if i in index_h:
            flag = False
            break
        if j in index_w:
            continue
        print(maze[i][j], end='')
    if flag:
        print()