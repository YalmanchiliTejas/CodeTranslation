from itertools import compress

H, W = map(int, input().split())
grid = [input() for _ in range(H)]

nonwhiterow = [any(c == '#' for c in row) for row in grid]
nonwhitecol = [any(row[i] == '#' for row in grid) for i in range(W)]

for row in compress(grid, nonwhiterow):
    comp = compress(row,  nonwhitecol)
    print(''.join(comp))
