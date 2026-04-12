MOD = 10 **9 + 7
INF = 10 ** 10
def main():
    H,W = map(int,input().split())
    grid = [list(input()) for _ in range(H)]
    for i in range(H - 1,-1,-1):
        flag = True
        for j in range(W):
            if grid[i][j] == '#':
                flag = False
                break
        if flag:
            grid = grid[:i] + grid[i + 1:]
            H -= 1

    for i in range(W - 1,-1,-1):
        flag = True
        for j in range(H):
            if grid[j][i] == '#':
                flag = False
                break
        if flag:
            for j in range(H):
                grid[j] = grid[j][:i] + grid[j][i + 1:]
    for i in range(H):
        print(''.join(grid[i]))
if __name__ == '__main__':
    main()