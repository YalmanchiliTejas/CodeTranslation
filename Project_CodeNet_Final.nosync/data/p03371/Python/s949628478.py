A, B, C, X, Y = map(int, input().split())

ans = float('inf')
for k in range(0, 2 * max(X, Y) + 1, 2):
    i = max(X - k // 2, 0)
    j = max(Y - k // 2, 0)
    ans = min(ans, A * i + B * j + C * k)

print(ans)
