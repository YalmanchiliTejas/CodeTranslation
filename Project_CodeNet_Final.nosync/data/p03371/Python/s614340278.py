A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(max(X,Y)+1):
    cost = 2 * C * i + max(0,X-i)*A +max(0,Y-i)*B
    ans = min(ans,cost)
print(ans)