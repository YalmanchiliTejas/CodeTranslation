A, B, C, X, Y = map(int, input().split())

ans = float('inf')
for i in range(max(X, Y) + 1):
    cost = 0
    cost += max(0, A * (X - i))
    cost += max(0, B * (Y - i))
    cost += C * i * 2
    ans = min(ans, cost)
print(ans)
