A, B, C, X, Y = list(map(int, input().split()))

ans = float('infinity')
for i in range(max(X + 1, Y + 1)):
    ans = min(max((X - i), 0) * A + max((Y - i), 0) * B + i * C * 2, ans)

print(ans)
