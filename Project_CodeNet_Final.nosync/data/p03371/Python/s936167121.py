a, b, c, x, y = map(int, input().split())
ans = 0

if a + b > c * 2:
    MIN = min(x, y)
    ans += c * (MIN * 2)
    x -= MIN
    y -= MIN
    if x > 0 and a < c * 2:
        ans += x * a
    elif y > 0 and b < c * 2:
        ans += y * b
    else:
        ans += max(x, y) * (c * 2)
else:
    ans += a * x + b * y

print(ans)