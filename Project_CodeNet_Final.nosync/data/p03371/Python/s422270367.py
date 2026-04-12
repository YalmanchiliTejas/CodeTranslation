import sys
a, b, c, x, y = [int(i) for i in sys.stdin.readline().split()]
if a + b < 2 * c:
    print(x * a + y * b)
else:
    if x > y:
        if a <= c * 2:
            print(c * y * 2 + a * (x - y))
        else:
            print(c * x * 2)
    else:
        if b <= c * 2:
            print(c * x * 2 + b * (y - x))
        else:
            print(c * y * 2)