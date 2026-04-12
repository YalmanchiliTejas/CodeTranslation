h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

dy = [0, 1]
dx = [1, 0]

stack = [[0 for _ in range(w)] for _ in range(h)]

def dfs(y, x):
    stack[y][x] = 1
    if x == w-1 and y == h-1:
        return
    for i in range(2):
        ny = y + dy[i]
        nx = x + dx[i] 
        if ny < 0 or ny >= h or nx < 0 or nx >= w:
            continue
        if a[ny][nx] == "#":
            dfs(ny, nx)
            break
    return

dfs(0, 0)
for i in range(h):
    for j in range(w):
        if a[i][j] == "#" and stack[i][j] == 0:
            print('Impossible')
            exit()
print('Possible')