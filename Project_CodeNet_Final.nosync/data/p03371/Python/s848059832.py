A, B, C, X, Y = map(int, input().split())

ans = 1e9
for c in range(max(X, Y)+1):
    a = max(X-c, 0)
    b = max(Y-c, 0)
    ans = min((A*a + B*b + 2*C*c), ans)

print(ans)
