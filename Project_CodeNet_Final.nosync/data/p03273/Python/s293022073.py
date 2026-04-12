H, W = map(int, input().split())
grid = [list(input()) for _ in range(H)]

h = []
for x in range(H):
    if all(a == '.' for a in grid[x]):
        h.append(x)
w = []
for y in range(W):
    if all(grid[x][y] == '.' for x in range(H)):
        w.append(y)


for x in range(H):
    if x in h:
        continue
    ans = []
    for y in range(W):
        if y not in w:
            ans.append(grid[x][y])
    print(*ans, sep='')
