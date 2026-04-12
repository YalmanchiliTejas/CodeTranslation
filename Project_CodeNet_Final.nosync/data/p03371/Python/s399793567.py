import sys

stdin = sys.stdin

ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline()

a, b, c, x, y = na()
ct = 0
if a + b < 2 * c:
    print(a * x + b * y)
else:
    ct += 2 * c * min(x, y)
    if x < y:
        if b > 2 * c:
            ct += 2 * c * (y - x)
        else:
            ct += b  * (y - x)
    elif x > y:
        if a > 2 * c:
            ct += 2 * c * (x - y)
        else:
            ct += a  * (x - y)
    print(ct)