H, W = map(int, input().split())

w_chk = [1]*W
h_chk = [1]*H
stock = []

for i in range(H):
        grid = list(input())
        stock.append(grid)
        for j in range(W):
            if not grid[j] == '.':
                w_chk[j] *= 0
                h_chk[i] *= 0

w_chk = [i for i, x in enumerate(w_chk) if x == 0]

for i in range(H):
    if h_chk[i] == 1:
        continue
    for j in w_chk:
        print(stock[i][j], end='')
    print('\n')