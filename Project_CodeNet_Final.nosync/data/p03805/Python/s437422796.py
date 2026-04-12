import sys
import heapq
input = sys.stdin.readline

N, M, = map(int, input().split())
L = [[int(v) for v in input().split()] for _ in range(M)]
t = [set() for _ in range(N)]

for i in range(M):
    x, y = L[i]
    
    t[x - 1].add(y - 1)
    t[y - 1].add(x - 1)

ans = 0
def dfs(now, visited):
    global ans
    
    if len(visited) == N:
        ans += 1
        return
    
    for v in t[now]:
        if v not in visited:
            dfs(v, visited + [v])

    return

dfs(0, [0])
print(ans)