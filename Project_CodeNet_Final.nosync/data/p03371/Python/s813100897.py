a, b, c, x, y = map(int, input().split())

cnt = max(x, y)

ans = 1 << 60
for i in range(cnt + 1):
    ans = min(ans, 2 * i * c + max(x - i, 0) * a + max(y - i, 0) * b)

print(ans)