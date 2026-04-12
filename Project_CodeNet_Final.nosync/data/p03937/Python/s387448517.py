H,W = map(int,input().split())
grid = []
X = [['.']*W for _ in range(H)]
for i in range(H):
    grid.append(list(input()))
cur = 0
for i in range(H):
    if grid[i][cur] == '.':
        print('Impossible')
        exit()
    grid[i][cur] = '.'
    if cur != W-1:
        while grid[i][cur+1] == '#':
            grid[i][cur+1] = '.'
            cur += 1
            if cur == W-1:
                break

if grid != X:
    print('Impossible')
else:
    print('Possible')