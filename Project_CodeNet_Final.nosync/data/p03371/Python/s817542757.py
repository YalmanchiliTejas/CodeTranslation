a, b, c, x, y = map(int, input().split())
ans = float('inf')
for i in range(100001):
    ans = min(ans, c * 2 * i + max(x - i, 0) * a + max(y - i, 0) * b)
print(ans)