H, W = map(int, input().split())

maze = [list(input()) for _ in range(H)]

siro_yoko = []
#w_yoko = [False] * W
for i in range(H):
    w_yoko = [False] * W
    for j in range(W):
        #w_yoko = [False] * W
        if maze[i][j] == '.':
            w_yoko[j] = True
    if all(w_yoko):
        siro_yoko.append(i)
    

siro_tate = []
for j in range(W):
    h_tate = [False] * H
    for i in range(H):
        if maze[i][j] == '.':
            h_tate[i] = True
    if all(h_tate):
        siro_tate.append(j)

for i in range(H):
    yoko = ""
    for j in range(W):
        if not i in siro_yoko and  j not in siro_tate:
            yoko += maze[i][j]
    if yoko:
        print(yoko)
    else:
        print('', end='')