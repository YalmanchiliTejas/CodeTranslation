h, w = map(int, input().split())
grid = []
for i in range(h):
    grid.append(list(input()))



grid = list(filter(lambda r: any([i=='#' for i in r]), grid))
grid = zip(*grid)
grid = list(filter(lambda r: any([i=='#' for i in r]), grid))
grid = zip(*grid)
for i in grid:
    print(''.join(i))