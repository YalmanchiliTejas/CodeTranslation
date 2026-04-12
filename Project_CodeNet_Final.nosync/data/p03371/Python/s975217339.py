a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
ans = min(ans, 2 * c * max(x, y))
if x > y:
    ans = min(ans, 2 * c * y + a * (x - y))
else:
    ans = min(ans, 2 * c * x + b * (y - x))
print(ans)