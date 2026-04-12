A, B, C, X, Y = map(int, input().split())

ans = 10 ** 9
for i in range(10 ** 5 + 1):
    tmp = 2 * i * C + max(X - i, 0) * A + max(Y - i, 0) * B
    ans = min(ans, tmp)

print(ans)
