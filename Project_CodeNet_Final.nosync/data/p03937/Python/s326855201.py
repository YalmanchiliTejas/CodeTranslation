from collections import deque
def bfs(sy,sx,gy,gx):
    q=deque([[sy,sx]])
    visited[sy][sx]=0
    while q:
        y,x=q.popleft()
        if [y,x]==[gy,gx]:
            return visited[y][x]
        for i,j in ([1,0],[-1,0],[0,1],[0,-1]):
            ny,nx=y+i,x+j
            if ny<0 or ny>h-1 or nx<0 or nx>w-1:continue
            if path[ny][nx]=="#" and visited[ny][nx]==-1:
                visited[ny][nx]=visited[y][x]+1
                q.append([ny,nx])
h,w=map(int,input().split())
path=[input() for i in range(h)]
visited=[[-1]*w for _ in range(h)]
c=0
for p in path:
    for pp in p:
        if pp=='#':
            c+=1

sy,sx=0,0
gy,gx=h-1,w-1
bfs(sy,sx,gy,gx)
if visited[gy][gx]==h+w-2 and c==h+w-1:
    print('Possible')
else:
    print('Impossible')
