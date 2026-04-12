A, B, C, X, Y = map(int, input().split())

ans = A * X + B * Y

for i in range(100001):
    total = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i)
    ans = min(ans, total)

print(ans)
