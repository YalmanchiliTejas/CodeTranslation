h,w = map(int,input().split())
a = [list(input()) for _ in range(h)]
count = 0
for y in range(h):
    for x in range(w):
        if a[y][x]=="#":
            count += 1
            
visited = [[0]*w for _ in range(h)]
q = [(0,0)]
visited[0][0] = 1
while q:
    cy,cx = q.pop()
    for dy,dx in ((1,0),(0,1)):
        ny,nx = cy+dy,cx+dx
        if (0<=ny<h and 0<=nx<w and a[ny][nx]=="#" and visited[ny][nx]==0):
            visited[ny][nx] = visited[cy][cx]+1
            q.append((ny,nx))
            
if visited[h-1][w-1]==count:
    print('Possible')
else:
    print('Impossible')