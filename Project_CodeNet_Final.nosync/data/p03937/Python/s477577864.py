from collections import deque
dx=[0,1]
dy=[1,0]
def bfs(x,y):
    que=deque([(x,y)])
    while(que):
        nx,ny=que.popleft()
        seen[nx][ny]=True
        if (nx+1<H-1 and G[nx+1][ny]=='#') and (ny+1<W-1 and G[nx][ny+1]=='#'):
            return False
        elif nx+1<H and G[nx+1][ny]=='#':
            que.append((nx+1,ny))
            continue
        elif ny+1<W and G[nx][ny+1]=='#':
            que.append((nx,ny+1))
            continue
        else:
            if nx==H-1 and ny==W-1:
                return True
            else:
                return False
    return True


memo={}
H,W=map(int,input().split())
G=[list(input()) for i in range(H)]
seen=[[False]*W for i in range(H)]
isok=bfs(0,0)
for i in range(H):
    for j in range(W):
        if G[i][j]=='#' and seen[i][j]==False:
            isok=False
print("Possible" if isok else "Impossible")