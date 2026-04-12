from collections import deque
def bfs(maze, visited, sy, sx, gy, gx):
    queue = deque([[sy, sx]])
    visited[sy][sx] = 0
    while queue:
        y, x = queue.popleft()
        if maze[y+1][x]=="#" and maze[y][x+1]=="#":
            return("Impossible")
        for j, k in ([-1, 0], [0, -1]):
            new_y, new_x = y+j, x+k
            if maze[new_y][new_x] == "#" and visited[new_y][new_x] == -1:
                return("Impossible")
        for j, k in ([1, 0], [0, 1]):
            new_y, new_x = y+j, x+k
            if maze[new_y][new_x] == "#" and visited[new_y][new_x] == -1:
                visited[new_y][new_x] = visited[y][x] + 1
                queue.append([new_y, new_x])
        if x==gx and y==gy:
            return("Possible")
h,w=map(int,input().split())
sy,sx=1,1
gy,gx=h,w
maze =["$"*(w+2)]+["$"+input()+"$" for i in range(h)]+["$"*(w+2)]
visited = [[-1]*(w+2) for j in range(h+2)]
print(bfs(maze, visited, sy, sx, gy, gx))