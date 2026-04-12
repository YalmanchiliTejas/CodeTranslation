a, b, c, x, y = map(int, input().split())
if c < (a + b) / 2:
    if (c < a and c < b) and (c * 2 <= a or c * 2 <= b):
        ans = c * 2 * max(x, y)
    else:
        ans = c * 2 * min(x, y)
        if x > y:
            ans += a * abs(y - x)
        elif x < y:
            ans += b * abs(y - x)
else:
    ans = a * x + b * y
print(ans)
