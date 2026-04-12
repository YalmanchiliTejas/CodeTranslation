a, b, c, x, y = map(int, input().split())

num = min(a + b, c * 2)
a = min(a, c * 2)
b = min(b, c * 2)
s = min(x, y)

if x > y:
    print(num * s + a * (x - s))
else:
    print(num * s + b * (y - s))
