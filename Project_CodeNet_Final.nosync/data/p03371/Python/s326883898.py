A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for c_2 in range(10**5 + 1):
    a = max(X - c_2, 0)
    b = max(Y - c_2, 0)
    ans = min(ans, a * A + b * B + c_2 * C * 2)
print(ans)