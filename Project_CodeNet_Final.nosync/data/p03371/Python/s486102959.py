A, B, C, X, Y = map(int, input().split())

max_iter = max(X, Y) * 2
ans = float("inf")
for i in range(max_iter):
    a = max(X - i, 0)
    b = max(Y - i, 0)
    price = 2*C * i + A * a + B * b
    ans = min(ans, price)

print(ans)