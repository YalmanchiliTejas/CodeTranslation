(a, b, c, x, y) = map(int, input().split())
print(str(min(max(x, y) * c * 2, min(x, y) * c * 2 + a * (x - min(x, y))+ b * (y - min(x, y)), a * x + b * y)))