import itertools

h,w = map(int,input().strip().split())
grid = []
for _ in range(h):
    grid.append(list(input().strip()))

grid = filter(lambda r: any(map(lambda c : c == '#', r)), grid)
grid = zip(*grid)
grid = filter(lambda r: any(map(lambda c : c == '#', r)), grid)
grid = zip(*grid)

for r in grid:
    print(''.join(r))
