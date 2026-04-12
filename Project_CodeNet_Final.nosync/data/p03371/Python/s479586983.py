# Half and Half
a, b, c, x, y = map(int, input().split())
ans = 0
if a + b >= 2 * c:
    if x >= y:
        ans += c * 2 * y
        x = max(x-y, 0)
        y = 0
    else:
        ans += c * 2 * x
        y = max(y-x, 0)
        x = 0
if a >= 2 * c:
    ans += c * 2 * x
    y = max(y - x, 0)
    x = 0
if b >= 2 * c:
    ans += c * 2 * y
    x = max(x - y, 0)
    y = 0
ans += a * x + b * y
print(ans)
