h, w = map(int, input().split())
grid = [list(input()) for i in range(h)]

for i in range(2):
    grid = [col for col in grid if '#' in col ]
    grid = list(map(list, (zip(*grid))))

for g in grid:
    print(''.join(g))