a, b, c, x, y = map(int, input().split())
INF = 10 ** 9
cost = INF
if x < y:
    x, y = y, x
    a, b = b, a
for i in range(x + 1):
    cost = min(cost, 2 * c * i + a * max(x - i, 0) + b * max(y - i, 0))

print(cost)
