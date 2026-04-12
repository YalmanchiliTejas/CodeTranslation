from bisect import bisect_left


def dfs(n, X):
    p = bisect_left(layer[n], X)
    if n == 0:
        return 1
    if p == 0:
        return 0
    elif p == 1:
        return dfs(n - 1, X - 1)
    elif p == 2:
        return patty[n - 1] + 1
    elif p == 3:
        return patty[n - 1] + 1 + dfs(n - 1, X - layer[n][2])
    else:
        return 2 * patty[n - 1] + 1


N, X = map(int, input().split())

layer = [0] * (N + 1)
layer[0] = [1]
for i in range(N):
    t = layer[i][-1]
    layer[i + 1] = [1, 1 + t, 1 + t + 1, 1 + t + 1 + t, 1 + t + 1 + t + 1]


patty = [0] * (N + 1)
patty[0] = 1
for i in range(N):
    t = patty[i]
    patty[i + 1] = 1 + 2 * t


print(dfs(N, X))
