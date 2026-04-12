def main():
    H, W = (int(_) for _ in input().split())
    board = [input() for _ in range(H)]
    num = 0
    for i in range(H):
        for j in range(W):
            if board[i][j] == '#': num += 1

    def dfs(x, y, n):
        if x == H-1 and y == W-1: return n == num
        nx = x + 1
        if 0 <= nx < H and board[nx][y] == '#':
            if dfs(nx, y, n+1):
                return True
        ny = y + 1
        if 0 <= ny < W and board[x][ny] == '#':
            if dfs(x, ny, n+1):
                return True
        return False

    print('Possible' if dfs(0, 0, 1) else 'Impossible')
    return

if __name__ == '__main__':
    main()
