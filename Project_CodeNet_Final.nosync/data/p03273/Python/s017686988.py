H,W = map(int,input().split())
grid = []

for h in range(H):
    s = input()
    if '#' in s:
        grid.append(s)

dl = []
ans = [''] * len(grid)
for i in range(W):
    l = ''
    for j in range(len(grid)):
        g = grid[j]
        ans[j] += g[i]
        l += g[i]
    if '#' not in l:
        for k in range(len(grid)):
            ans[k] = ans[k][:-1]

for i in range(len(ans)):
    str = ''
    for j in range(len(ans[i])):
        str += ans[i][j]
    print(str)
