H, W = map(int, input().split())

grid = []
for i in range(H):
    s = input()
    if s != "." * W:
        grid.append(list(s))

H = len(grid)

for i in reversed(range(W)):
    if all(grid[j][i] == "." for j in range(H)):
        for k in range(H):
            grid[k].pop(i)

print("\n".join("".join(r) for r in grid))