a, b, c, x, y = map(int, input().split())

ans = 0
if c < (a + b) / 2:
    if x < y:
        ans += x * 2 * c
        if b < c * 2:
            ans += (y - x) * b
        else:
            ans += (y - x) * c * 2
    else:
        ans += y * 2 * c
        if a < c * 2:
            ans += (x - y) * a
        else:
            ans += (x - y) * c * 2
elif c * 2 < a:
    ans += x * c * 2
    if y > x:
        ans += (y - x) * b
elif c * 2 < b:
    ans += y * c * 2
    if x > y:
        ans += (x - y) * a
else:
    ans += x * a + y * b
print(ans)
