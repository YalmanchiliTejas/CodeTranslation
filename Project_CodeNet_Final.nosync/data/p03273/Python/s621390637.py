H,W = map(int,input().split(" "))
grid = []
h = H
for i in range(h):
    row = input()
    if row == "."*W:
        H -= 1
        continue
    grid.append(list(row))
for i in range(W):
    flag = True
    for j in range(H):
        if grid[j][i] == "#":
            flag = False
    if flag == True:
        for j in range(H):
            grid[j][i] = ""
for i in range(H):
    row = ""
    for j in range(W):
        row += grid[i][j]
    print(row)