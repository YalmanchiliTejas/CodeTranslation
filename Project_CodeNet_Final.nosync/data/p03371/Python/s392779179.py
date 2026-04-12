a, b, c, x, y = map(int, input().split())
ans = 10 ** 18
for i in range(10 ** 5 * 2):
    ans = min(ans, i * 2 * c + max(0, x - i) * a + max(0, y - i) * b)
print(ans)
