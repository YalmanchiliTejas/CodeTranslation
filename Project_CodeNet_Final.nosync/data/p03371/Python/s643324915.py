a, b, c, x, y = list(map(int, input().split()))

if 2 * c >= a + b:
    print(x * a + y * b)
else:
    if x >= y:
        ans = y * 2 * c
        ans += (x - y) * a
    else:
        ans = x * 2 * c
        ans += (y - x) * b

    tmp = max(x, y) * (2 * c)
    print(min(tmp, ans))
