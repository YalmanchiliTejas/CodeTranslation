a, b, c, x, y = map(int, input().split())

ans1 = a * x + b * y
ans2 = 2 * c * max(x, y)
z = min(x, y)
ans3 = 2 * c * z + a * (x - z) + b * (y - z)
print(min(ans1, ans2, ans3))