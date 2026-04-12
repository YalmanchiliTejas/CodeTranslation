a, b, c, x, y = map(int, input().split())
ans = x * a + y * b

for i in range(1, 10 ** 5 + 1):
    ans = min(ans, max(x - i, 0) * a + max(y - i, 0) * b + i * 2 * c)

print(ans)