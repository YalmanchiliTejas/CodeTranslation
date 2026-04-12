a, b, c, x, y = map(int, input().split())

cost = 0
if (a + b) / 2 > c:
    cost = 2 * c * min(x, y)
    cost += min(a, 2 * c) * max(0, x - y) + min(b, 2 * c) * max(0, y - x)
else:
    cost = a * x + b * y

print(cost)