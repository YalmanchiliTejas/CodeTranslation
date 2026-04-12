a, b, c, x, y = [int(x) for x in input().split()]

if x <= y:
    ans = min(a + b, 2 * c) * x
    ans += min(b, 2 * c) * (y - x)
else:
    ans = min(a + b, 2 * c) * y
    ans += min(a, 2 * c) * (x - y)

print(ans)