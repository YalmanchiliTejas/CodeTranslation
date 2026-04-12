def generate_transposed_grid(grid):
    t_grid = [[None] * len(grid) for i in range(len(grid[0]))]
    for i in range(len(grid)):
        for j in range(len(grid[0])):
            t_grid[j][i] = grid[i][j]
    return t_grid


def generate_compressed_grid(grid):
    return [s for s in grid if not s == ['.'] * len(s)]


H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]

for _ in range(2):
    grid = generate_compressed_grid(grid)
    grid = generate_transposed_grid(grid)

for s in grid:
    print(''.join(s))
