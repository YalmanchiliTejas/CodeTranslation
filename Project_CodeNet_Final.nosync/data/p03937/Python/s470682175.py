H,W=map(int,input().split())
field=[]
for i in range(H):
    s=input()
    a=[]
    for j in range(W):
        a.append(s[j])
    field.append(a)

def dfs(x,y):
    field[x][y]='.'
    dx=[0,1]
    dy=[1,0]
    for i in range(2):
        nx=x+dx[i]
        ny=y+dy[i]
        if 0<=nx and nx<H and 0<=ny and ny<W and field[nx][ny]=="#":
            dfs(nx,ny)
            break
    return

dfs(0,0)

for i in range(H):
    for j in range(W):
        if field[i][j]=='#':
            print('Impossible')
            exit()
print('Possible')