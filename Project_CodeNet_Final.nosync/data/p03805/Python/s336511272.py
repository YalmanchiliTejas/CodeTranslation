from collections import deque

N,M = map(int, input().split())
table = [[] for i in range(N)]
ans = 0

for i in range(M):
    a,b = map(int, input().split())
    a -= 1
    b -= 1
    table[a].append(b)
    table[b].append(a)

Q = deque()
Q.append(0)
visited = [0]*N

def DFS(x):
    global ans
    if visited[x] == 1:
        return
    visited[x] = 1
    if all(visited):
        ans += 1
        visited[x] = 0
        return
    for nx in table[x]:
        if visited[nx] == 0:
            DFS(nx)
    visited[x] = 0
DFS(0)
print(ans)
