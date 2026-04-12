a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
ans = min(c * max(x, y) * 2, ans)
if x < y:
    ans = min(c * x * 2 + (y - x) * b, ans)
else:
    ans = min(c * y * 2 + (x - y) * a, ans)

print(ans)