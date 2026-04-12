

n = input()
a = map(int, raw_input().split())
oo = sum(a) + 1

dp_max = [[-oo] * n for _ in range(n)]
dp_min = [[oo] * n for _ in range(n)]

for i in range(n):
    dp_max[i][i] = a[i]
    dp_min[i][i] = -a[i]

for i in range(1, n):
    for j in range(n - i):
        k = i + j
        dp_max[j][k] = max(dp_min[j + 1][k] + a[j], dp_min[j][k - 1] + a[k])
        dp_min[j][k] = min(dp_max[j + 1][k] - a[j], dp_max[j][k - 1] - a[k])
print(dp_max[0][n - 1])
