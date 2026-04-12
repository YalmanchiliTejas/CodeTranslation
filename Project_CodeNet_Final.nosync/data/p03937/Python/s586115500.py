import sys
sys.setrecursionlimit(10**6)

def check(y,x):
    if 0<=y<=h-1 and 0<=x<=w-1:
        if g[y][x]=="#":
            return True
    return False

def dfs(y,x):
    dx=(0,1)
    dy=(1,0)
    if y==h-1 and x==w-1:
        return True
    for i in xrange(2):
        nxy=y+dy[i]
        nxx=x+dx[i]
        if check(nxy,nxx) and not visited[nxy][nxx]:
            visited[nxy][nxx]=True
            if dfs(nxy,nxx):
                return True
            visited[nxy][nxx]=False
    return False

h,w=map(int,raw_input().split())
g=[raw_input() for _ in xrange(h)]
visited=[[False]*w for _ in xrange(h)]
visited[0][0]=True
if not dfs(0,0):
    print("Impossible")
    exit()
for i in xrange(h):
    for j in xrange(w):
        if g[i][j]=="#" and not visited[i][j]:
            print("Impossible")
            exit()
print("Possible")