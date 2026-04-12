H, W = map(int, input().split())
a = [list(input()) for i in range(H)]

flag_row = [True] * H
flag_col = [True] * W

for i in range(H):
    cnt = 0
    for j in range(W):
        if a[i][j] == '.':
            cnt += 1
    if cnt == W:
        flag_row[i] = False

for j in range(W):
    cnt = 0
    for i in range(H):
        if a[i][j] == '.':
            cnt += 1
    if cnt == H:
        flag_col[j] = False

for i in range(H):
    for j in range(W):
        if flag_row[i] == True and flag_col[j] == True:
            print(a[i][j], end='')
    if flag_row[i] == True:
        print()