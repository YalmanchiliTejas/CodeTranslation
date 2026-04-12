a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
    print(a * x + b * y)
else:
    m = min(x, y)
    ans = 2 * c * m
    if x != m:
        if a > 2 * c:
            ans += 2 * c * (x - m)
        else:
            ans += a * (x - m)
    else:
        if b > 2 * c:
            ans += 2 * c * (y - m)
        else:
            ans += b * (y -m)
    print(ans)