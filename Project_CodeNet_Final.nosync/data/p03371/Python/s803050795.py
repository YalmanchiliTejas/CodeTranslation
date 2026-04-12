a, b, c, x, y = map(int, input().split())
ans = 10 ** 12
for i in range(10 ** 5 + 5):
    ans = min(ans, i * 2 * c + max((x - i), 0) * a + max((y - i), 0) * b)
print(ans)
