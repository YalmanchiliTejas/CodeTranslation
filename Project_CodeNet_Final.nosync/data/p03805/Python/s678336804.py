import copy
import sys
sys.setrecursionlimit(10**7)
N, M = map(int, input().split())
edges = [[] for _ in range(N)]
for _ in range(M):
    a, b = map(int, input().split())
    edges[a - 1].append(b - 1)
    edges[b - 1].append(a - 1)
ans = 0
def dfs(start,path):
    next_path = copy.copy(path)
    global ans
    next_path.append(start)
    if len(next_path) == N:
        ans += 1
        return
    for i in edges[start]:
        if i not in next_path:
            dfs(i,next_path)
dfs(0,[])
print(ans)