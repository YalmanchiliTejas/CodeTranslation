a, b, c, x, y = map(int, input().split())

ans = 0
if a + b > c * 2:
    d = min(x, y)
    ans += c * d * 2
    x -= d
    y -= d

if x > 0:
    if a > c * 2:
        ans += x * c * 2
    else:
        ans += x * a

if y > 0:
    if b > c * 2:
        ans += y * c * 2
    else:
        ans += y * b

print(ans)
