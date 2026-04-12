n, m = map(int,input().split())
lis = [0 for i in range(m)]
for i in range(m):
    lis[i] = list(map(int,input().split()))
    
seen = []
count = 0
visited = [0 for i in range(n)]
def route(x=1):
    visited[x-1] = 1
    if [1]*n == visited:
        global count
        count +=1
        return
    for i in range(m):
        if lis[i][0] == x and visited[lis[i][1]-1] == 0:
            route(lis[i][1])
            visited[lis[i][1]-1] = 0
        elif lis[i][1] == x and visited[lis[i][0]-1] == 0:
            route(lis[i][0])
            visited[lis[i][0]-1] = 0
    return
            
        
route(1)
print(count)