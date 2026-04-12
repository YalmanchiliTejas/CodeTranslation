INF = 10 ** 9
a, b, c, x, y = map(int, input().split())

ans = INF
for i in range(10 ** 5 + 1):
    ans = min(ans, i * 2 * c + max((x - i), 0) * a + max((y - i), 0) * b)
print(ans)
