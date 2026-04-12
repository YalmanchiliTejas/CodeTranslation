# ABC 107: B – Grid Compression
h, w = [int(s) for s in input().split()]
a = [input() for _ in range(h)]

grid_after_operations = []

for i in range(h):
    if a[i] != '.' * w:
        grid_after_operations.append(a[i])

for j in reversed(range(w)):
    if grid_after_operations[0][j] == '.':
        for i in range(1, len(grid_after_operations)):
            if grid_after_operations[i][j] != '.':
                break
        else:
            for i in range(len(grid_after_operations)):
                grid_after_operations[i] = grid_after_operations[i][:j] + grid_after_operations[i][j + 1:]

for i in range(len(grid_after_operations)):
    print(grid_after_operations[i])