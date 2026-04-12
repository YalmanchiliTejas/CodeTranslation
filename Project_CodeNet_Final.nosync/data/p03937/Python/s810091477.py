import sys
sys.setrecursionlimit(10000)
H, W = map(int, input().split())
A = [input() for _ in range(H)]
homon = [[False]*W for _ in range(H)]
dx = [0, 1]
dy = [1, 0]

def dfs(x, y):
    homon[y][x] = True
    if x == W-1 and y == H-1:
        return
    for i in range(2):
        nx = x + dx[i]
        ny = y + dy[i]
        if nx < 0 or W <= nx or ny < 0 or H <= ny:
            continue
        if A[ny][nx] == '#':
            dfs(nx, ny)
            break
    return 

if __name__ == '__main__':
    dfs(0, 0)
    for i in range(H):
        for j in range(W):
            if A[i][j] == '#' and homon[i][j] == False:
                print('Impossible')
                exit()
    print('Possible')
