a, b, c, x, y = (int(x) for x in input().split())
ans = 10**18
ans = min(ans, a * x + b * y)
z = min(x, y)
ans = min(ans, 2 * c * z + a * (x - z) + b * (y - z))
ans = min(ans, 2 * c * max(x, y))
print(ans)
