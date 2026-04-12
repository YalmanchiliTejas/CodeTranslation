H,W = map(int,input().split())

grid = []

for i in range(H):
    line = input()
    if line == '.'*W:
        continue
    grid.append(list(line))

for j in range(W):
    line = ''
    for i in range(len(grid)):
        line += grid[i][j]
    if line == '.'*len(grid):
        for i in range(len(grid)):
            grid[i][j] = '0'

for i in range(len(grid)):
    line = grid[i]
    line = ''.join(line).replace('0','')
    print(line)
