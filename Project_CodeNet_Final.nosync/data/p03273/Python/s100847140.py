H, W = map(int, input().split())
grid = []

for h in range(H):
    temp = []
    line = input()
    for w in range(W):
        temp.append(line[w])
    grid.append(temp)

for h in range(H):
    if all([grid[h][w] == '.' for w in range(len(grid[h]))]):
        for w in range(len(grid[h])):
            grid[h][w] = ''

for w in range(W):
    if all([grid[h][w] in ('', '.') for h in range(len(grid))]):
        for h in range(len(grid)):
            grid[h][w] = ''

for h in range(len(grid)):
    if not all([grid[h][w] == '' for w in range(len(grid[h]))]):
        print(''.join(grid[h]))