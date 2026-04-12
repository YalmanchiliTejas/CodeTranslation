a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
    ans = a * x + b * y
elif x < y:
    ans = min(
        2 * c * x + b * (y - x), 2 * c * y
    )
elif y <= x:
    ans = min(
        2 * c * y + a * (x - y), 2 * c * x
    )
print(ans)
