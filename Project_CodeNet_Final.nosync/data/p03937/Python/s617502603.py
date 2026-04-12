# input
H, W = map(int, input().split())
board = [['.']*W for i in range(H)]
v_board = [[True]*W for i in range(H)]
sign_count = 0
for i in range(H):
    s = input()
    for j in range(W):
        if s[j]=='#':
            sign_count += 1
        board[i][j] = s[j]

if sign_count==H+W-1:
    print("Possible")
else:
    print("Impossible")
