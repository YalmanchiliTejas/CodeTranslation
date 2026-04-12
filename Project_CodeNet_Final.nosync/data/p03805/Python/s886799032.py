import sys
sys.setrecursionlimit(10000000)
import copy

n, m = map(int, input().split())
graph = [list() for i in range(n+1)]
for i in range(m):
   a, b = map(int, (input().split()))
   graph[a] += [b]
   graph[b] += [a]

ans = 0

def dfs(visited, now):
    tv = copy.copy(visited)
    tv[now-1] = True
    
    if all(tv):
        return 1

    temp = 0
    for i in graph[now]:
        if tv[i-1] != 1:
            temp += dfs(tv, i)
    return temp

ans = dfs([False] * n, 1)
print(ans)