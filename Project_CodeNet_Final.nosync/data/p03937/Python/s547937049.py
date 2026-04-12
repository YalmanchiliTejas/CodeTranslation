# Problem A - Shik and Stone

# input
H, W = map(int, input().split())
board = [['']*W for i in range(H)]
for i in range(H):
    s = list(input())
    for j in range(W):
        board[i][j] = s[j]

# initialization
max_pos = 0
is_ok = True

# check
for i in range(H):
    tmp_min_pos = W
    tmp_max_pos = 0
    for j in range(W):
        if board[i][j]=='#':
            tmp_min_pos = min(tmp_min_pos, j)
            tmp_max_pos = max(tmp_max_pos, j)
    if not tmp_min_pos==max_pos:
        is_ok = False
    max_pos = tmp_max_pos

if is_ok:
    print("Possible")
else:
    print("Impossible")
