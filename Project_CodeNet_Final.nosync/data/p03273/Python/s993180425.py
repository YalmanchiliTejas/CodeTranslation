# https://atcoder.jp/contests/abc107/tasks/abc107_b
h, w = [int(i) for i in input().split()]
grid = []

for _ in range(h):
    line = list(input())
    if "#" in line:
        grid.append(line)

ans = [[] for _ in range(len(grid))]

for i in range(w):
    for j in range(len(grid)):
        if grid[j][i] == "#":
            break
    else:
        continue
    for k in range(len(grid)):
        ans[k].append(grid[k][i])

for line in ans:
    print("".join(line))
