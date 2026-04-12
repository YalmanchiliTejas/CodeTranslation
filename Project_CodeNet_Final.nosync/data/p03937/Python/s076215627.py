# def dfs(y, x):
#     if gridgraph[y+1][x] == "#" and y+1 != H:
#         visited[y+1][x] = True
#         dfs(y+1, x)
#     elif gridgraph[y][x+1] == "#" and x+1 != W:
#         visited[y][x+1] = True
#         dfs(y, x+1)
#     elif y == H-1 and x == W-1:
#         return

from collections import deque

H, W = map(int, input().split())
gridgraph = [input() for _ in range(H)]
# 移動経路を右or下のみに限定して，目的地に着いたかどうか判定する, 幅優先探索で右と下が同時に#なら終わりという制約でもいいかも
q = deque()
q.append([0, 0])
visited = [[False]*W for _ in range(H)]
adjacents = [[1, 0], [0, 1]]
while len(q):
    ny, nx = q.popleft()
    # print(ny, nx)
    visited[ny][nx] = True
    if (ny+1 != H and gridgraph[ny+1][nx] == "#") and (nx+1 != W and gridgraph[ny][nx+1] == "#"):
        break
    if (ny+1 != H and gridgraph[ny+1][nx] != "#") and (nx+1 != W and gridgraph[ny][nx+1] != "#"):
        break
    for dy, dx in adjacents:
        if ny+dy == H or nx+dx == W:
            continue
        if gridgraph[ny+dy][nx+dx] == "#":
            q.append([ny+dy, nx+dx])
ans = True
for i in range(H):
    for j in range(W):
        if visited[i][j] == False and gridgraph[i][j] == "#":
            ans = False

if ny == H-1 and nx == W-1 and ans:
    print("Possible")
else:
    print("Impossible")
