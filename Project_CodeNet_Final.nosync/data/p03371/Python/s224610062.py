A, B, C, X, Y = map(int, input().split())
ans = 10 ** 18
for i in range(10 ** 5+1):
    t = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i)
    ans = min(ans, t)
print(ans)
