H,W = map(int,input().split())
A = [input() for _ in range(H)]

visited = [[False for j in range(W)] for i in range(H)]
visited[0][0] = True

x,y = 0,0

while not (x==H-1 and y==W-1):
    if x<H-1 and A[x+1][y]=='#':
        x += 1
        visited[x][y] = True
    elif y<W-1 and A[x][y+1]=='#':
        y += 1
        visited[x][y] = True
    else:
        break
ans = True
for i in range(H):
    for j in range(W):
        if A[i][j] == '#' and not visited[i][j]:
            ans = False

print('Possible' if ans else 'Impossible')