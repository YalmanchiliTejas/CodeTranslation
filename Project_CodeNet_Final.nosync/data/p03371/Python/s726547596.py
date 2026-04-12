import sys
 
stdin = sys.stdin
 
ni = lambda: int(ns())
na = lambda: list(map(int, stdin.readline().split()))
ns = lambda: stdin.readline().rstrip()
nas = lambda: stdin.readline().split()

a, b, c, x, y = na()

ans = 0
while x or y:
    if x and y:
        if a + b > c * 2:
            z = min(x, y)
            x -= z
            y -= z
            ans += c * 2 * z
        else:
            z = min(x, y)
            x -= z
            y -= z
            ans += (a + b) * z
    else:
        q = c * 2 * (x + y)
        if q <= a * x + b * y:
            ans += c * 2 * (x + y)
            x = 0
            y = 0
        if x:
            ans += a * x
            x = 0
        if y:
            ans += b * y
            y = 0

print(ans)