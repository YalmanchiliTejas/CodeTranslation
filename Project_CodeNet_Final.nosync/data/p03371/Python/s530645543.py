a, b, c, x, y = map(int, input().split())
if c * 2 > a + b:
    print(a * x + b * y)
else:
    ans = c * 2 * min(x, y)

    z = x - min(x, y)
    if z > 0:  # Aを買い足す必要あり
        ans += min(a * z, 2 * c * z)

    z = y - min(x, y)
    if z > 0:  # Bを買い足す必要あり
        ans += min(b * z, 2 * c * z)
    print(ans)
