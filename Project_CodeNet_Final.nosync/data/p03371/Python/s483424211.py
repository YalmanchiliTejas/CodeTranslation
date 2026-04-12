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
            x -= 1
            y -= 1
            ans += c * 2
        else:
            x -= 1
            y -= 1
            ans += a + b
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