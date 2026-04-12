h, w = map(int, input().split())
grid = []
for _ in range(h):
    grid.append(input())

grid = [i for i in grid if i.count('#')>0]
c = []
for j in range(w):
    for i in range(len(grid)):
        if grid[i][j]=='#':
            break
    else:
        c.append(j)
for row in grid:
    tmp = ''
    s = 0
    for i in c:
        tmp += row[s:i]
        s = i+1
    tmp += row[s:]
    print(tmp)

