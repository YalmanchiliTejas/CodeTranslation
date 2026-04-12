H, W = [int(i) for i in input().split()]

grid = [""]*W

for _ in range(H):
    tmp = input()
    if "."*W != tmp:
        for i, x in enumerate(tmp):
            grid[i] += x
j = len(grid[0])
ans = [""]*j
for row in grid:
    if "."*j != row:
        for i, s in enumerate(row):
            ans[i] += s


for r in ans:
    print(r)
