from collections import deque

def dfs(maze, cnt, x, y):
    global H, W, count, can
    if x == H-1 and y == W-1:
        if cnt == count:
            can = "Possible"
    for dx, dy in ([1, 0], [0, 1]):
        new_x , new_y = x + dx, y + dy
        if new_x < 0 or new_x >= H or new_y < 0 or new_y >= W:
            continue
        elif maze[new_x][new_y] == '#':
            cnt += 1
            dfs(maze, cnt, new_x, new_y)
            cnt -= 1

if __name__ == "__main__":
    H, W = map(int, input().split())
    maze = []
    for _ in range(H):
        a = [c for c in input()]
        maze.append(a)
    count = 0
    for h in range(H):
        for w in range(W):
            if maze[h][w] == '#':
                count += 1
    cnt = 1 
    can = "Impossible"
    dfs(maze, cnt, 0, 0)
    print(can)
