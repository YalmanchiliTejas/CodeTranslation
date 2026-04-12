h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
d=[[1,0],[0,1]]
def dfs(x,y):
    a[x][y]="."
    for i in d:
        if 0<=x+i[0]<h and 0<=y+i[1]<w and a[x+i[0]][y+i[1]]=="#":
            dfs(x+i[0],y+i[1])
            break
dfs(0,0)
# for i in range(h):
#     print(a[i])
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            print("Impossible")
            exit()
print("Possible")
