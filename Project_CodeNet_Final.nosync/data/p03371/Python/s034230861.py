a, b, c, x, y = map(int, input().split())
ans = 0
if c * 2 < a + b:
    m = min(x, y)
    ans += m * c * 2
    x -= m
    y -= m
if c * 2 < a:
    ans += x * c * 2
else:
    ans += x * a
if c * 2 < b:
    ans += y * c * 2
else:
    ans += y * b
print(ans)