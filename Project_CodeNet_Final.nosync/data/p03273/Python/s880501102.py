h, w = map(int, input().split())
grid = []

for _ in range(0, h):
    grid.append(input())

while True:
    modified = False

    for i in range(0, h):
        if all(True if grid[i][j] == "." else False for j in range(0, w)):
            del grid[i]

            modified = True
            h       -= 1

            break

    for j in range(0, w):
        if all(True if grid[i][j] == "." else False for i in range(0, h)):
            for i in range(0, h):
                grid[i] = grid[i][0:j] + grid[i][j + 1:]

            modified = True
            w       -= 1

            break

    if not modified:
        break

for r in grid:
    print(r)