A, B, C, X, Y = map(int, input().split())
ans = X * A + Y * B
for nab in range(2, max(X, Y) * 2 + 2, 2):
    price = nab * C
    price += max(X - (nab // 2), 0) * A
    price += max(Y - (nab // 2), 0) * B
    ans = min(ans, price)
print(ans)