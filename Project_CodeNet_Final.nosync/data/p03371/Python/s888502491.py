A, B, C, X, Y = map(int, input().split())

ans = float('inf')
for ab in range(0, max(X, Y)*2+1, 2):
    a = max(0, X - ab//2)
    b = max(0, Y - ab//2)
    ans = min(ans, A * a + B * b + C * ab)

print(ans)
