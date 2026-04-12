h, w = map(int, input().split())

grid = []
del_cnt = 0
for i in range(h):
    row = input()
    if '#' in row:
        grid.append(row)
    else:
        del_cnt += 1
ans = []
for i in range(w):
    col = ""
    for j in range(h-del_cnt):
        col += grid[j][i]
    if '#' in col:
        ans.append(i)

for i in range(h-del_cnt):
    tmp = ""
    for a in ans:
        tmp += grid[i][a]
    print(tmp)