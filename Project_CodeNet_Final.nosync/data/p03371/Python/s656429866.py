A, B, C, X, Y = map(int, input().split())

ans = float("inf")
for c in range(0, max(X, Y)*2+1, 2):
    ans = min(A*max(X-c//2, 0) + B*max(Y-c//2, 0) + C*c, ans) 

print(ans)