a, b, c, x, y = map(int, input().split())

cost1 = a * x + b * y
cost2 = c * max(x, y) * 2
if x < y:
    cost3 = c * x * 2 + b * (y - x)
else:
    cost3 = c * y * 2 + a * (x - y)
print(min(cost1, cost2, cost3))