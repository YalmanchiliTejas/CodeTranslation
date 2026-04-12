from itertools import combinations
H,W = map(int,input().split())
grid = [0] * H
for i in range(H):
    grid[i] = list(input())
res = 'Impossible'
# 1は右、0は下
move_indexes = [i for i in range(H+W-2)]
# 移動回数W+Hの中からH回縦移動を選ぶ
for y_move in combinations(move_indexes,H-1):
    now_y, now_x = 0,0
    reached = [[0]*W for _ in range(H)]
    reached[0][0] = 1
    for i in range(H+W-2):
        # うまくやれば*1/8にはなる
        if i in y_move:
            now_y += 1
        else:
            now_x += 1
        reached[now_y][now_x] = 1
    can = True
    for i in range(H):
        for j in range(W):
            if (not reached[i][j] and grid[i][j]=='#') or (reached[i][j] and grid[i][j] == '.'):
                can = False
    if can:
        res = 'Possible'
        break

print(res)


