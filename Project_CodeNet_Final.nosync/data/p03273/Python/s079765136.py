H, W = map(int, input().split())

white = [0]*W
board = []
for _ in [0]*H:
    line = input().rstrip()
    for i in range(W):
        if line[i] == '.': white[i] += 1
    if '#' in line:
        board.append(list(line))

for line in board:
    for i in range(W):
        if white[i] == H: continue
        else: print(line[i], end='')
    print()