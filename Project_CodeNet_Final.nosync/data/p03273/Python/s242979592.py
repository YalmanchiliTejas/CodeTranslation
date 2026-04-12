h, w = list(map(int, input().split()))
init_board = []
for i in range(h):
    init_board.append([_ for _ in input()])

board = []
# 行から削除する
for i in range(h):
    if init_board[i] != ["."] * w:
        board.append(init_board[i])

# 行列を転置する
new_board = []
for i in range(w):
    add_row = []
    for j in range(len(board)):
        add_row.append(board[j][i])
    if add_row != ["."] * len(add_row):
        new_board.append(add_row)

# 最後に形を戻す
answer_board = []
for i in range(len(new_board[0])):
    add_row = []
    for j in range(len(new_board)):
        add_row.append(new_board[j][i])
    answer_board.append(add_row)

# 出力
for i in range(len(answer_board)):
    print("".join(answer_board[i]))
