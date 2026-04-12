a, b, c, x, y = map(int, input().split())

ans = 0
if a + b <= c * 2:
    ans += a * x + b * y
else:
    if x == y:
        ans += c * 2 * x
        x, y = 0, 0
    elif x > y:
        ans += c * 2 * y
        x -= y
        y = 0
    elif y > x:
        ans += c * 2 * x
        y -= x
        x = 0
    if x > 0:
        if a <= c * 2:
            ans += a * x
        else:
            ans += c * 2 * x
    elif y > 0:
        if b <= c * 2:
            ans += b * y
        else:
            ans += c * 2 * y

print(ans)