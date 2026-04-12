from collections import defaultdict
n, m = map(int, input().split())

ans = 0
G = defaultdict(list)
vis = [0] * n
for i in range(m):
    a, b = map(int, input().split())
    G[a - 1].append(b - 1)
    G[b - 1].append(a - 1)


def dfs(k, cnt):
    global ans

    vis[k] = 1

    if cnt == n - 1:
        ans += 1
    else:
        for i in G[k]:
            if vis[i] == 0:
                dfs(i, cnt + 1)

    vis[k] = 0


dfs(0, 0)
print(ans)
