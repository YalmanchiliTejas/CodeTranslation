n, m=  map(int, input().split())
grid = []
for i in range(n):
    grid.append(list(input()))
i = 0
while i < n:
    replace = True
    for j in range(m):
        if grid[i][j] != '.':
            replace = False
            break
    if replace:
        grid.pop(i)
        n -= 1
    else:
        i+=1
i = 0
while i < m:
    replace = True
    for j in range(n):
        if grid[j][i] != '.':
            replace = False
            break
    if replace:
        for x in range(n):
            grid[x].pop(i)
        m-=1
    else:
        i+=1
for i in range(n):
    for j in range(m):
        print(grid[i][j], end='')
    print()