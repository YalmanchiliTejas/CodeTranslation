from collections import deque
h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

queue = deque()
queue.append([0, 0])
visited = [[False] * w for _ in range(h)]
visited[0][0] = True

def judge():
    for i in range(h):
        for j in range(w):
            if a[i][j] == "#" and not visited[i][j]:
                return False
    return True
def bfs(queue):
    while len(queue) > 0:
        n_y, n_x = queue.popleft()
        if 0 <= n_x < w - 1 and 0 <= n_y < h - 1:
            if a[n_y][n_x + 1] == "#" and a[n_y + 1][n_x] == "#":
                print("Impossible")
                exit()
        for i, j in [[0, 1], [1, 0]]:
            y, x = n_y + i, n_x + j
            if 0 <= x < w and 0 <= y < h:
                if a[y][x] == "#":
                    queue.append([y, x])
                    visited[y][x] = True
    print("Possible" if judge() else "Impossible")
bfs(queue)
