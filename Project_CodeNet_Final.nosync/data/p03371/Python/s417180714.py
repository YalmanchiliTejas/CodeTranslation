A, B, C, X, Y = map(int, input().split())
ans = float("inf")
for i in range(max(X, Y) + 1):
    cost = C * 2 * i + A * max(0, X - i) + B * max(0, Y - i)
    ans = min(ans, cost)
print(ans)
