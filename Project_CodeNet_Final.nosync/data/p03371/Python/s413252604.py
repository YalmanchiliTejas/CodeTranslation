a, b, c, x, y = map(int, input().split())
ans = float("inf")
for i in range(100001):
    ans = min(ans, i * 2 * c + a * max(0, x - i) + b * max(0, y - i))
print(ans)
