a, b, c, x, y = map(int, input().split())

ans1 = a * x + b * y
ans2 = min(x, y) * 2 * c + [a, b][max(x, y) == y] * abs(x - y)
ans3 = max(x, y) * 2 * c

print(min(ans1, ans2, ans3))