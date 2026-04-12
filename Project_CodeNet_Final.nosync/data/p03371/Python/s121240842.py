a, b, c, x, y = list(map(int, input().split()))

if x < y:
    if 2 * c < b:
        print(2 * y * c)
    elif b  <= 2 * c <= (a + b):
        print((y - x) * b + 2 * x * c)
    else:
        print(x * a + y * b)
else:
    if 2 * c < a:
        print(2 * x * c)
    elif a <= 2 * c <= (a + b):
        print((x - y) * a + 2 * y * c)
    else:
        print(x * a + y * b)
