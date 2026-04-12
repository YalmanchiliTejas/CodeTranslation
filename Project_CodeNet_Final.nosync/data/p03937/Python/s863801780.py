H,W = map(int,input().split())
A = [input() for i in range(H)]

from collections import deque
dxy = [(0,1),(1,0)]
dist = [[0]*W for i in range(H)]
visited = [[0]*W for i in range(H)]
visited[0][0] = 1
q = deque([(0,0)])
while q:
    x,y = q.popleft()
    for dx,dy in dxy:
        nx,ny = x+dx,y+dy
        if not 0 <= nx < W: continue
        if not 0 <= ny < H: continue
        if visited[ny][nx]: continue
        if A[ny][nx] == '.': continue
        visited[ny][nx] = 1
        dist[ny][nx] = dist[y][x] + 1
        q.append((nx,ny))

cnt = sum(row.count('#') for row in A)
print('Possible' if dist[-1][-1]+1 == cnt else 'Impossible')