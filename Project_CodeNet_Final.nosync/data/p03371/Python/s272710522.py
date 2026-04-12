A, B, C, X, Y = [int(_) for _ in input().split()]
ans = A * X + B * Y
for i in range(max(X, Y) + 1):
    cost = 2 * C * i
    if X > i:
        cost += A * (X - i)
    if Y > i:
        cost += B * (Y - i)
    ans = min(ans, cost)
print(ans)