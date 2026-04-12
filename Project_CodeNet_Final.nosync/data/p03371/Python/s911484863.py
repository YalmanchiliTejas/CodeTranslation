a, b, c, x, y = map(int, input().split())
if a + b > 2 * c and x > y:
    if a > 2 * c:
        ans = 2 * x * c
    else:
        ans = (x - y) * a + 2 * y * c
elif a + b > 2 * c and x <= y:
    if b > 2 * c:
        ans = 2 * y * c
    else:
        ans = (y - x) * b + 2 * x * c
else:
    ans = x * a + y * b
print(ans)