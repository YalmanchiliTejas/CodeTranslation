import numpy as np
n, m = map(int, input().split())
if m == 0:
    print(0)
    exit()
r = [[] for i in range(n)]
for i in range(m):
    f, s = map(int, input().split())
    r[f-1].append(s - 1)
    r[s-1].append(f - 1)
ans = []
def dfs(now, visited = []):
    global ans
    if len(visited) == n:
        ans.append([visited])
        return
    for j in r[now]:
        if j not in visited:
            dfs(j, visited + [j])
dfs(0, [0])
print(len(ans))