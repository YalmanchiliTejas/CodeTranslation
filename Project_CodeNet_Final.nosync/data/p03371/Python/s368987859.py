a, b, c, x, y = map(int, input().split())
if x == y:
    print(min(2 * c, a + b) * x)
elif x < y:
    print(x * min(2 * c, a + b) + (y - x) * min(b, 2 * c))
else:
    print(y * min(2 * c, a + b) + (x - y) * min(a, 2 * c))
