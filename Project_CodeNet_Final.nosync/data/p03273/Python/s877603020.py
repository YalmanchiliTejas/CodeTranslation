H, W = map(int, input().split())
grid = [input() for _ in range(H)]

grid = [a for a in grid if '#' in a]

grid = list(zip(*[a for a in zip(*grid) if '#' in a]))
for a in grid:
    print(''.join(a))
