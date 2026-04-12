a, b, c, x, y = [int(_) for _ in input().split()]
ans = 0
if a + b <= 2*c:
    ans = a * x + b * y
else:
    if x <= y:
        ans += x * 2 * c
        if b <= 2*c:
            ans += (y-x) * b
        else:
            ans += (y-x) * 2 * c
    else:
        ans += y * 2 * c
        if a <= 2*c:
            ans += (x-y) * a
        else:
            ans += (x-y) * 2 * c
print(ans)