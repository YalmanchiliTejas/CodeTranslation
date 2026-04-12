H, W = map(int, input().split())
grid = []

for i in range(0, H):
    temp = list(input())
    grid.append(temp)

yoko = []
tate = []
for i in range(0, H):
    judge = True
    for j in range(0, W):
        if grid[i][j] != '.':
            judge = False
    if judge:
        yoko.append(i)
        
for i in range(0, W):
    judge = True
    for j in range(0, H):
        if grid[j][i] != '.':
            judge = False
    if judge:
        tate.append(i)


for i in range(0, H):
    for j in range(0, W):
        if i in yoko or j in tate:
            pass
        else:
            print(grid[i][j], end='')
    if not i in yoko:
        print('')