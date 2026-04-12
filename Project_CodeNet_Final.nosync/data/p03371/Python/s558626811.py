a, b, c, x, y = map(int, input().split())
a1 = a * x + b * y
a2 = min(x, y) * c * 2 + ((x - y) * a if x > y else (y - x) * b)
a3 = max(x, y) * c * 2
print(min(a1, a2, a3))
