a, b, c, x, y = map(int, input().split())
ans = 0
if a + b <= 2 * c:
    print(a * x + b * y)
else:
    ans += c * min(x, y) * 2
    z = abs(x-y)
    if x == y:
        pass
    elif x > y:
        if a >= 2 * c:
            ans += 2 * c * z
        else:
            ans += a * z
    else:
        if b >= 2 * c:
            ans += 2 * c * z
        else:
            ans += b * z
    print(ans)