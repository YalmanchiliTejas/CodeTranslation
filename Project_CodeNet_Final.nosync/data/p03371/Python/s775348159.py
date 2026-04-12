a, b, c, x, y = map(int, input().split())
ab = c * 2

res = float("inf")
if a + b <= ab:
    res = x * a + y * b
else:
    if x == y:
        res = x * ab
    elif x > y:
        for i in range(y, x + 1):
            cost = i * ab + (x - i) * a
            res = min(res, cost)
    else:
        for i in range(x, y + 1):
            cost = i * ab + (y - i) * b
            res = min(res, cost)
print(res)
