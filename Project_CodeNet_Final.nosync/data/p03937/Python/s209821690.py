def check(grid, h, w):
    for i in range(h):
        for j in range(w):
            if grid[i][j] == '#':
                return False
    return True


def main():
    h, w = map(int, input().split())

    grid = []
    for _ in range(h):
        grid.append(list(input()))
    # 右、下、左、上
    dy = [0, 1]
    dx = [1, 0]
    stack = [[0, 0]]
    grid[0][0] = 'D'
    while stack:
        y, x = stack.pop()
        for i in range(2):
            next_y = y + dy[i]
            next_x = x + dx[i]
            if 0 <= next_y < h and 0 <= next_x < w and grid[next_y][next_x] == '#':
                grid[next_y][next_x] = 'D'
                stack.append([next_y, next_x])
                break
    if check(grid, h, w):
        print('Possible')
        return
    print('Impossible')

if __name__ == "__main__":
    main()