# A - Shik and Stone
si = lambda: input()
ni = lambda: int(input())
nm = lambda: map(int, input().split())
nl = lambda: list(map(int, input().split()))
from collections import deque
def bfs(sy,sx):
    q = deque([[sy,sx]])
    visited[sy][sx]=0
    while q:
        y,x = q.popleft()
        for j,k in ([1,0],[-1,0],[0,1],[0,-1]):
            ny,nx = y+j,x+k
            if ny<0 or ny>h-1 or nx<0 or nx>w-1 or a[ny][nx]==".":
                continue
            if a[ny][nx]=="#" and visited[ny][nx]==-1:
                visited[ny][nx]=visited[y][x]+1
                q.append([ny,nx])
    ret=-1
    for i in range(h):
        for j in range(w):
            ret=max(visited[i][j],ret)
    return ret
h,w=nm()
a=[input() for i in range(h)]
visited = [[-1]*w for i in range(h)]
dist=0
dist=bfs(0,0)
cnt=0
for aa in a:
    cnt+=aa.count('#')
if dist==h+w-2 and dist==cnt-1:
    print('Possible')
else:
    print('Impossible')