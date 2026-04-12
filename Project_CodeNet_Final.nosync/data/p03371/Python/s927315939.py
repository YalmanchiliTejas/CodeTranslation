A, B, C, X, Y = map(int, input().split())
ans = 10**18
for z in range(0, max(X, Y) * 2 + 1, 2):
    x, y = max(0, X - z // 2), max(0, Y - z // 2)
    tmp = A * x + B * y + C * z
    ans = min(ans, tmp)
print(ans)
