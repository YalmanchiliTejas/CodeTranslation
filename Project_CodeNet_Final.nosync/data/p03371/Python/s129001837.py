a, b, c, x, y = map(int, input().split())
ans = 0
if c * 2 <= a + b:
    ans += min(x, y) * c * 2
    if x >= y:
        ans += min(c * 2 * (x - y), a * (x - y))
    else:
        ans += min(c * 2 * (y - x), b * (y - x))
else:
    ans = a * x + b * y
print(ans)
