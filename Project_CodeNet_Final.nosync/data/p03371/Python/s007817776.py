a, b, c, x, y = map(int, input().split())

min_cost = 10000000000
for i in range(max(x, y) + 1):
    cost = 2 * c * i + max(0, a * (x - i)) + max(0, b * (y - i))

    if min_cost > cost:
        min_cost = cost
print(min_cost)
