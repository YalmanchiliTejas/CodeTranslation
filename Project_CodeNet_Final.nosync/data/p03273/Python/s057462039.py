H, W = list(map(int, input().split()))

grid = []

for _ in range(H):
    grid.append(input())

Hx = [ (True if '#' in grid[i] else False) for i in range(H) ]
Wx = [ (True if '#' in [grid[j][i] for j in range(H)] else False) for i in range(W) ]

for i in range(H):
    flag = False
    for j in range(W):
        if(Hx[i] and Wx[j]):
            flag = True
            print(grid[i][j], sep='', end='')
    if flag:
        print()
