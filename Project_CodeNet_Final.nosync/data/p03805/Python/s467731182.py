N, M = map(int,input().split())
ab = [list(map(int,input().split())) for i in range(M)]
visited = [0]*N
ans = 0
def move(vert):
    global ans
    visited[vert-1] = 1
    if sum(visited) == N:
        ans += 1
        visited[vert-1] = 0
        return 0 
    for i in range(M):
        if ab[i][0] == vert and visited[ab[i][1]-1] == 0:
            move(ab[i][1])
        elif ab[i][1] == vert and visited[ab[i][0]-1] == 0:
            move(ab[i][0])
    visited[vert - 1] = 0
    return ans
print(move(1))