a, b, c, x, y = map(int, input().split())
ans = 0
r = min(x, y)

if a + b > 2 * c:
    ans += (2 * c) * r
    x -= r
    y -= r
if a > 2 * c and x > 0:
    ans += (2 * c) * x
    y -= x
    x = 0
if b > 2 * c and y > 0:
    ans += (2 * c) * y
    x -= y
    y = 0
if x > 0:
    ans += a * x
if y > 0:
    ans += b * y
print(ans)