a, b, c, x, y = list(map(int, input().split()))
res = a * x + b * y
for i in range(1, max(x, y) + 1):
    res = min(res, a * max(x - i, 0) + b * max(y - i, 0) + 2 * c * i)
print(res)