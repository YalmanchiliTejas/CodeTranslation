import math

n, k = map(int, input().split())
res = 0
for b in range(1, n + 1):
    res += math.floor(n / b) * max(0, b - k) + max(0, n % b - k + 1)

if k == 0:
    res = n ** 2

print(res)
