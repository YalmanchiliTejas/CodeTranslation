a, b, c, x, y = [int(v) for v in input().split()]

if x < y:
    x, y = y, x
    a, b = b, a

ans = a * x + b * y
ans = min(ans, a * (x - y) + c * y * 2)
ans = min(ans, c * x * 2)
print(ans)