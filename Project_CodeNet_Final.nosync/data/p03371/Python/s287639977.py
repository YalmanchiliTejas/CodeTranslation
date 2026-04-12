A, B, C, X, Y = map(int, input().split())

# Cを購入する数をiとして、その時の最小値を求める
ans = 10 ** 9
for i in range(max(X + 1, Y + 1)):
    amount = C * 2 * i + A * max(X - i, 0) + B * max(Y - i, 0)
    ans = min(ans, amount)

print(ans)