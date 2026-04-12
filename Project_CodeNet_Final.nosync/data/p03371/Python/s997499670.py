a, b, c, x, y = map(int, input().split())

if 2 * c == min(2 * c, a, b):
    print(c * 2 * max(x, y))
elif 2 * c <= max(a, b) and a == max(a, b):
    print(c * 2 * x + b * max(y - x, 0))
elif 2 * c <= max(a, b) and b == max(a, b):
    print(c * 2 * y + a * max(x - y, 0))
elif 2 * c <= a + b and x <= y:
    print(c * 2 * x + b * (y - x))
elif 2 * c <= a + b and x > y:
    print(c * 2 * y + a * (x - y))
else:
    print(a * x + b * y)