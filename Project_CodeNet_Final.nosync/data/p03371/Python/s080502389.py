a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
ans = min(ans, 2 * x * c + max(0, y - x) * b)
ans = min(ans, 2 * y * c + max(0, x - y) * a)
print(ans)