h, w = map(int, input().split())
grid = []
for _ in range(h):
    grid.append(input())

row = [False]*h
col = [False]*w

for i in range(h):
    for j in range(w):
        if grid[i][j] == "#":
            row[i] = True
            col[j] = True

for i in range(h):
    if row[i]:
        for j in range(w):
            if col[j]:
                print(grid[i][j],end="")
        print("")

