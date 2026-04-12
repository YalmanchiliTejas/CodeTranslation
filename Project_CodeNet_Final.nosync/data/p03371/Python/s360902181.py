A, B, C, X, Y = map(int, input().split())
ans = A*X+B*Y
ans = min(max(X,Y)*C*2,ans)
if X > Y:
    ans = min(Y*C*2+(X-Y)*A, ans)
else:
    ans = min(X*C*2+(Y-X)*B, ans)
print(ans)