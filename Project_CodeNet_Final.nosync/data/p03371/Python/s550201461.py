a, b, c, x, y = [int(i) for i in input().split()]

if a+b <= 2*c:
    ans = a * x + b * y
else:
    if x >= y:
        ans = c * 2 * y
        ans += (a if a <= 2*c else 2*c) * (x - y)
    else:
        ans = c * 2 * x
        ans += (b if b <= 2*c else 2*c) * (y - x)

print(ans)
