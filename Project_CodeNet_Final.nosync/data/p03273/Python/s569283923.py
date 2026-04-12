h, w = list(map(int, input().split()))
grid = []
for i in range(h):
    temp = list(input())
    if "#" in temp:
        grid.append(temp)
    else:
        h -= 1
i = 0
while i < len(grid[0]):
    for j in range(h):
        if grid[j][i] == "#":
            i += 1
            break
        if j == h - 1:
            for k in range(h):
                del grid[k][i]
for i in range(h):
    print("".join(grid[i]))