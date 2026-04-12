from collections import deque


def bfs(start):
    Q = deque()
    Q.append(start)
    dist[start[1]][start[0]] = 0

    while Q:
        x, y = Q.popleft()

        for i in range(2):
            nx = x + dx[i]
            ny = y + dy[i]

            if not(0 <= nx < W and 0 <= ny < H):
                continue
            if G[ny][nx] == '.':
                continue
            if dist[ny][nx] != -1:
                continue

            Q.append((nx, ny))
            dist[ny][nx] = dist[y][x] + 1


H, W = map(int, input().split())
G = [[] for _ in range(H)]

n = 0
for i in range(H):
    G[i] = list(input())
    n += G[i].count('#')

dist = [[-1 for _ in range(W)] for _ in range(H)]
dx = [1, 0]  # 斜めも含むならその方向もプラス
dy = [0, 1]

bfs((0, 0))

if dist[H - 1][W - 1] + 1 == n:
    print("Possible")
else:
    print("Impossible")
