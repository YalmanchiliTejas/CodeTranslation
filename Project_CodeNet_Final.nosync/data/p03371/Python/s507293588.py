A, B, C, X, Y = map(int, input().split())

ans = float("inf")
for i in range(max(X, Y)+1):
    x = max(X - i, 0)
    y = max(Y - i, 0)
    cost = 2*C * i + A * x + B * y
    ans = min(ans, cost)

print(ans)