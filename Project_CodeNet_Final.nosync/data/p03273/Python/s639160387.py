H, W = map(int, input().split())
maze = [list(input()) for _ in range(H)]

rev_maze = [[0] * H for i in range(W)]
for i in range(W):
    for j in range(H):
        #rev_maze = 
        rev_maze[i][j] = maze[j][i]

ans_yoko = []
for i in range(H):
    if maze[i].count('.') == W:
        ans_yoko.append(i)
        
ans_tate = []
for i in range(W):
    if rev_maze[i].count('.') == H:
        ans_tate.append(i)

for i in range(H):
    ans = ''
    for j in range(W):
        #ans = ''
        if i in ans_yoko:
            continue
        if j in ans_tate:
            continue
        else:
            ans += maze[i][j]
    if i == any(ans_yoko) - 1:
        print(ans, end='')
    else:
        print(ans)