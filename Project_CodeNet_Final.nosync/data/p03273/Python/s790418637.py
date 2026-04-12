import sys

H, W = (raw_input()).split()
H = int(H)
W = int(W)

grid = []
for i in range(H):
    grid.append(raw_input())

new_grid = []
for i in range(H):
    if ('.'*W) != grid[i]:
        new_grid.append(grid[i])

for j in range(W):
    all_blanks = True
    for i in range(len(new_grid)):
        if new_grid[i][j] != '.':
            all_blanks = False
            break

    if all_blanks:
        for i in range(len(new_grid)):
            new_grid[i] = new_grid[i][:j] + 'b' + new_grid[i][j+1:]


for i in range(len(new_grid)):
    for j in range(W):
        if new_grid[i][j] != 'b':
            sys.stdout.write(new_grid[i][j])
    print
