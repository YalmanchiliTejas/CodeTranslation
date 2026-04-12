A, B, C, X, Y = map(int, input().split())

ans = 10 ** 18

for k in range(10 ** 5 + 10):
    ans = min(ans, 2 * C * k + max(0, X - k) * A + max(0, Y - k) * B)

print(ans)
