a, b, c, x, y = map(int, input().split())
ans = 10 ** 50
for i in range(10 ** 5 + 1):
    ans = min(ans, (2 * c * i + max(x - i, 0) * a + max(y - i, 0) * b))
print(ans)
