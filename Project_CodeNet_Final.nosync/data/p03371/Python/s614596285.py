a, b, c, x, y = map(int, input().split())

ans = 0
if a + b >= 2 * c:
    if x >= y:
        ans += y * c * 2
        x -= y
        y = 0
        if a >= c * 2:
            ans += x * c * 2
        else:
            ans += x * a
    else:
        ans += x * c * 2
        y -= x
        x = 0
        if b >= c * 2:
            ans += y * c * 2
        else:
            ans += y * b
else:
    ans += x * a + y * b

print(ans)