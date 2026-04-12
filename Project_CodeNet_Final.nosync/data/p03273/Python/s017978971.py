# use transpose by zip
h, w = map(int, input().split())

grid = [list(input()) for _ in range(h)]

for _ in range(2):
    grid = list(filter(lambda x: any(map(lambda x1: x1 == '#', x)), grid))
    grid = [list(x) for x in zip(*grid)]

for i in range(len(grid)):
    print(''.join(grid[i]))
