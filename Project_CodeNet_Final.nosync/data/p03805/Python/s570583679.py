import sys
sys.setrecursionlimit(10 ** 9)
def dfs(i, j):
    global cnt, vis
    if len(set(vis)) == 1:
        cnt += 1
        return None
    for k in l[j]:
        if not vis[k] == 1:
            vis[k] = 1
            dfs(i + 1, k)
            vis[k] = 0
n, m = map(int, input().split())
l = [[] for i in range(n)]
vis = [0] * n
vis[0] = 1
cnt = 0
for i in range(m):
    a, b = map(int, input().split())
    l[a - 1].append(b - 1)
    l[b - 1].append(a - 1)
dfs(0, 0)
print(cnt)