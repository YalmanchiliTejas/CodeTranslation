def lake(x,y):
    l[x][y] = "."
    for i in range(2):
        xi = x + dx[i]
        yi = y + dy[i]
        if 0 <= xi < n and 0 <= yi < m and l[xi][yi] == "#":
            lake(xi,yi)
            break


n,m = map(int, input().split())
l = [list(input()) for _ in range(n)]
l[0][0]=="."
dx = [1,0]
dy = [0,1]
lake(0,0)
for i in range(n):
    for j in range(m):
        if l[i][j] == "#":
            print("Impossible")
            exit()

print("Possible")
