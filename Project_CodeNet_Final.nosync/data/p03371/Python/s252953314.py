A, B, C, X, Y = map(int, input().split())

ans = max(A, B) * (X + Y)
for i in range(2 * 10 ** 5 + 100):
    c = i // 2
    x = i * C + max(X - c, 0) * A + max(Y - c, 0) * B
    ans = min(ans, x)

print(ans)
