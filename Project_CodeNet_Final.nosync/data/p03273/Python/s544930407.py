h,w = map(int,input().split())
grid = []
for i in range(h):
    grid.append(list(input()))
h_b = []
w_b = []
for i in range(h):
    if "#" in grid[i]:
        h_b.append(i)
grid_t = [list(x) for x in zip(*grid)]
for i in range(w):
    if "#" in grid_t[i]:
        w_b.append(i)
ans = []
for i in h_b:
    crt = []
    for j in w_b:
        crt.append(grid[i][j])
    ans.append(crt)
for i in range(len(ans)):
    print("".join(ans[i]))

