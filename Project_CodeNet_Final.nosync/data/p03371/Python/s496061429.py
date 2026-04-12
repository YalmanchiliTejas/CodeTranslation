a, b, c, x, y = map(int, input().split())

cost = [
    a * x + b * y,
    2 * c * max(x, y),
    2 * c * min(x, y) + (a if x > y else b) * abs(x - y)
]

print(min(cost))