"""
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
"""

a, b, c, x, y = map(int, input().split())
ab = 2 * c
m = 10 ** 9
for i in range(0, max(x, y) + 1):
    p = ab * i + a * max(0, x - i) + b * max(0, y - i)
    if m > p:
        m = p
print(m)