n, m = map(int, input().split())
edge = [[] for _ in range(n)]
for i in range(m):
    a, b = map(int, input().split())
    edge[a - 1].append(b - 1)
    edge[b - 1].append(a - 1)

flag = [False] * n
flag[0] = True
ans = 0

def dfs(x):
    global ans
    if all(flag):
        ans += 1
    for j in edge[x]:
        if not flag[j]:
            flag[j] = True
            dfs(j)
            flag[j] = False

dfs(0)
print(ans)
