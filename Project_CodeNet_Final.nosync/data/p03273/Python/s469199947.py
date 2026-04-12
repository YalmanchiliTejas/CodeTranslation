
H, W = map(int, input().split())

grid = []
cols = [True for _ in range(W)]
rows = [True for _ in range(H)]

for _ in range(H):
    tmp = input()
    grid.append(tmp);
    
for i in range(H):
    if grid[i].count('.') == W:
        rows[i] = False        


for i in range(W):
    count = 0
    for j in range(H):
        if grid[j][i] == '.':
            count += 1
    if count == H:
        cols[i] = False

for i in range(H):
    if rows[i]:
        for j in range(W):
            if cols[j]:
                print(grid[i][j], end="")
        print()