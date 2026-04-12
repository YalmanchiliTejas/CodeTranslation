N,M=list(map(int,input().split()))
a = [list(map(int,input().split())) for i in range(M)]
seen = [-1 for i in range(N)]
count = 0
def dfs(x):
    global count
    if sum(seen) == N:
        count += 1
        return
    
    for i in range(M):
        if a[i][0] == x and seen[a[i][1]-1] == -1:
            seen[a[i][1]-1] = 1
            dfs(a[i][1])
            seen[a[i][1]-1] = -1
        if a[i][1] == x and seen[a[i][0]-1] == -1:
            seen[a[i][0]-1] = 1
            dfs(a[i][0])
            seen[a[i][0]-1] = -1
seen[0] = 1
dfs(1)
print(count)
