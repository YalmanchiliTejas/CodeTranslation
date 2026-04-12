H, W = map(int, input().split())
grid = [list(str(input())) for _ in range(H)]

res = []
for h in range(H):
    for w in range(W):
        if grid[h][w] == "#":
            res.append(grid[h])
            break
    else:
        H -= 1

for w in range(W):
    for h in range(H):
        if res[h][w] == "#":
            break
    else:
        for i in range(H):
            res[i][w] = ""

for i in res:
    print("".join(i))