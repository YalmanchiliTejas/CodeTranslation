def dfs(grid, start, wall, h, w):
    stack = []
    push, pop = stack.append, stack.pop
    push(start)
    grid[start[0]][start[1]] = wall
    dxy = [(0,1), (1,0)]

    while stack:
        h, w = pop()
        cnt = 0
        for dx,dy in dxy:
            x, y = w+dx, h+dy
            if grid[y][x] == wall:
                continue
            push((y,x))
            grid[y][x] = wall
            cnt += 1
        if cnt > 1:
            return False
    for i in range(1, h+1):
        for j in range(1, w+1):
            if grid[i][j] != wall:
                return False
    return True


def resolve():
    h, w = map(int, input().split())
    grid = {}
    wall = '.'
    edges = [wall] * (w+2)
    grid = [edges]
    for i in range(h):
        s = input()
        grid.append([wall] + list(s) + [wall])
    grid.append(edges)
    print("Possible" if dfs(grid, (1, 1), wall, h, w) else "Impossible")

if __name__ == "__main__":
    resolve()
