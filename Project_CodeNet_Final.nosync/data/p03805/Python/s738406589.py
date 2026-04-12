n,m = map(int, input().split())
g = [[] for _ in range(n)]
for _ in range(m):
    a,b = map(int, input().split())
    g[a-1].append(b-1)
    g[b-1].append(a-1)



def dfs(x, y, l):
    if y == n - 1:
        return 1
    else:
        ans = 0
        for i in range(len(g[x])):
            if not g[x][i] in l:
                l2 = l + [g[x][i]]
                ans += dfs(g[x][i], y + 1, l2)
        return ans

print(dfs(0, 0, [0]))