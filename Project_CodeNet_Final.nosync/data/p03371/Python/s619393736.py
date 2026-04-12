a, b, c, x, y = map(int, input().split())
center = (a + b) / 2
res = 0
if center >= c:
    buy = min(x, y)
    res += buy * 2 * c
    x -= buy
    y -= buy
if x > 0 and a >= c * 2:
    res += x * 2 * c
    x = 0
if y > 0 and b >= c * 2:
    res += y * 2 * c
    y = 0
res += a * x
res += b * y
print(res)
