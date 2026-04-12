a, b, c, x, y = list(map(int, input().split()))

l = a * x + b * y
m = c * max(x, y) * 2

if x >= y :
    n = c * y * 2 +  a * (x - y)
else:
    n = c * x * 2 + b * (y - x)

ans = min(l, min(m, n))
print(ans)

