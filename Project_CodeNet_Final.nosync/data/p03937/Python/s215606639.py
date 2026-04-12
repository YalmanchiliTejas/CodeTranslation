#大きさがN*Mの庭がある. そこに雨が降り, 水溜りができた.
#水溜りは8近傍で隣接している場合に繋がっているとみなす.
#全部でいくつの水溜りがあるか.(8近傍とは, 次のWに対する*の部分を指す)
# ***
# *W*
# ***
#"W"は水溜りを, "."は水溜りでない所を表すとする
#1<=n,m<=100
n,m=map(int,input().split())
s = [list(input()) for i in range(n)]
def dfs(x,y):
    c=False
    s[x][y]='.'
    for i in range(0,2):
        for j in range(0,2):
            if i==1 and j==1:
                continue
            nx=i+x
            ny=j+y
            if 0<=nx<n and 0<=ny<m and s[nx][ny]=='#':
                #print(nx,ny)
                c=True
                dfs(nx,ny)
            if c:
                break
        if c:
            break
ans=0
for i in range(n):
    for j in range(m):
        if s[i][j]=='#':
            #print("------------")
            #print(i,j)
            dfs(i,j)
            ans+=1
            #print(s)
if ans<=1:
    print("Possible")
else:
    print("Impossible")