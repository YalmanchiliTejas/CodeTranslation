a, b, c, x, y = map(int, input().split())
if a + b <= c * 2:
    print(a * x + b * y)
else:
    if x <= y:
        print(c * min(x, y) * 2 + abs(x - y) * min(b, c * 2))
    else:
        print(c * min(x, y) * 2 + abs(x - y) * min(a, c * 2))
