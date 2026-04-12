import sys
H, W = map(int, input().split())

grid = [[0] for h in range(H)]
#print(grid)
for h in range(H):
    line = list(input())
    grid[h] = line

last = 0
for h in range(H):
    if '#' not in grid[h]:
        print('Impossible')
        sys.exit()
    for w in range(last, W - 1):
        if grid[h][w] == '.' and grid[h][w + 1] == '#':
            print('Impossible')
            sys.exit()
    for w in range(W):
        if grid[h][w] == '#' and w < last:
            print('Impossible')
            sys.exit()
        elif grid[h][w] == '#' and w >= last:
            last = w
print('Possible')