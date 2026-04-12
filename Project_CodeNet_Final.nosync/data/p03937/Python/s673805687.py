h,w=map(int,input().split())
a=[list(input()) for i in range(h)]

def bfs(y,x):
    a[y][x]='.'
    
    if y+1<h and x+1<w:
        if a[y+1][x]=='#' :
            bfs(y+1,x)
        elif a[y][x+1]=='#':
            bfs(y,x+1)
    elif x+1<w:
        if a[y][x+1]=='#':
            bfs(y,x+1)
    elif y+1<h:
        if a[y+1][x]=='#':
            bfs(y+1,x)
    
bfs(0,0)

ans='Possible'
for i in a:
    if '#' in i:
        ans='Impossible'
        
print(ans)
    