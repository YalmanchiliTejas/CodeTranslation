A, B, C, X, Y = map(int, input().split())
ans = A * X + B * Y
for i in range(1, max(X, Y) + 1):
    ab_n = i * 2
    mix = C * ab_n + A * max(0, X - i) + B * max(0, Y - i)
    ans = min(ans, mix)
print(ans)
