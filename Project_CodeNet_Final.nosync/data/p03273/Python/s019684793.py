from collections import Counter
H, W = list(map(int, input().split()))
board = [list(input()) for _ in range(H)]
board = [b for b in board if b.count('.') < W]

b_r = []

for i in range(len(board[0])):
    r = [b[i] for b in board]
    b_r.append(r.count('.'))

idx = [i for i, x in enumerate(b_r) if x == len(board)]

for n in idx[::-1]:
    for b in board:
        b.pop(n)

for b in board:
    print(*b, sep='')
