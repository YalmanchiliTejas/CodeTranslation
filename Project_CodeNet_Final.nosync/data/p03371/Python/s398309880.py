a, b, c, x, y = map(int, input().split())
if (a + b) / 2 < c:
    print(a*x + b*y)
else:
    ans = c * min(x, y) * 2
    if x > y:
        if a < c * 2:
            ans += a * (x - y)
        else:
            ans += c * 2 * (x - y)
    else:
        if b < c * 2:
            ans += b * (y - x)
        else:
            ans += c * 2 * (y - x)
    print(ans)