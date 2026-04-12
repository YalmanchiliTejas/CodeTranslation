from collections import deque


H, W = map(int, input().split())
field = [list(input()) for _ in range(H)]
q = deque([(0, 0, [(0, 0)])])
visited = {(0, 0)}
while q:
    i, j, path = q.popleft()
    if (i, j) == (H - 1, W - 1):
        for pi, pj in path:
            field[pi][pj] = "."
        break
    for di, dj in ((1, 0), (0, 1)):
        ni, nj = i + di, j + dj
        if (
            0 <= ni < H
            and 0 <= nj < W
            and field[ni][nj] == "#"
            and (ni, nj) not in visited
        ):
            visited.add((ni, nj))
            q.append((ni, nj, path + [(ni, nj)]))

if any("#" in row for row in field):
    print("Impossible")
else:
    print("Possible")
