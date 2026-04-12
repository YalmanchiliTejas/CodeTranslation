n = int(input())
a = [*map(int, input().split())]
for i in range(n * 3):
    a[i] -= 1

INF = 1<<30
dp = [[-INF] * n for i in range(n)]
mx = [-INF] * n
mx_all = -INF
add_all = 0

dp[a[0]][a[1]] = dp[a[1]][a[0]] = 0
mx[a[0]] = mx[a[1]] = 0
mx_all = 0

for i in range(n - 1):
    x, y, z = sorted(a[i * 3 + 2 : i * 3 + 5])
    update = []
    # パターン1
    if x == y == z:
        add_all += 1
        continue
    # パターン2
    if x == y:
        for j in range(n):
            update.append((j, z, dp[j][x] + 1))
    if y == z:
        for j in range(n):
            update.append((j, x, dp[j][y] + 1))
    # パターン3
    update.append((y, z, dp[x][x] + 1))
    update.append((x, z, dp[y][y] + 1))
    update.append((x, y, dp[z][z] + 1))
    # パターン2-2
    for j in range(n):
        update.append((j, x, mx[j]))
        update.append((j, y, mx[j]))
        update.append((j, z, mx[j]))
    # パターン3-2
    update.append((y, z, mx_all))
    update.append((x, z, mx_all))
    update.append((x, y, mx_all))
    # in-place にするために更新を遅延させる
    for j, k, val in update:
        if dp[j][k] < val:
            dp[j][k] = dp[k][j] = val
        if mx[j] < val:
            mx[j] = val
        if mx[k] < val:
            mx[k] = val
        if mx_all < val:
            mx_all = val

# 最後の 1 回
if mx_all < dp[a[-1]][a[-1]] + 1:
    mx_all = dp[a[-1]][a[-1]] + 1
print(mx_all + add_all)