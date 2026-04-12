a, b, c, x, y = map(int, input().split())

min_cost = float("inf")

for ab_pizza in range(0, max(x, y)*2+1, 2):
    cost = a * max(x - ab_pizza // 2, 0) + b * max(y - ab_pizza // 2, 0) + c * ab_pizza
    if cost < min_cost:
        min_cost = cost

print(min_cost)
