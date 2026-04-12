ans = 0
a, b, c, x, y = map(int, input().split())
if a+b <= 2*c:
    ans += a * x
    ans += b * y
else:
    if y > x:
        x, y = y, x
        a, b = b, a

    ans += c * y * 2
    x -= y
    y = 0
    if a * x > 2 * c * x:
        ans += 2 * c * x
    else:
        ans += a * x
print(ans)
