A, B, C, X, Y = map(int, input().split())

ans = 10 ** 9
for c in range(max(X, Y) + 1):
    tmp = 2 * C * c
    tmp += A * max(0, X - c)
    tmp += B * max(0, Y - c)
    ans = min(ans, tmp)

print (ans)