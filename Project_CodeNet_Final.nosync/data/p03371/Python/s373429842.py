a, b, c, x, y = map(int, input().split())

cost_min = 1000000 * 5000
for i in range(2 * max(x, y) + 1):
    cost = c * i
    if x - i // 2 > 0:
        cost += a * (x - i // 2)
    if y - i // 2 > 0:
        cost += b * (y - i // 2)
    cost_min = min(cost, cost_min)
print(cost_min)