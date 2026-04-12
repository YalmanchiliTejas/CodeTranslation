a, b, c, x, y = map(int, input().split())
ans = a * x + b * y
for i in range(0, 2 * max(x, y) + 2, 2):
    pay = max(0, (x - i / 2)) * a + max(0, (y - i / 2)) * b + c * i
    ans = min(ans, pay)
print(int(ans))
