A, B, C, X, Y = map(int, raw_input().split())
ans = A*X + B*Y
for k in range(0, max(X, Y)+1):
    ans = min(ans, A * max(0, X-k) + B * max(0, Y-k) + C * 2 * k)
print ans