A, B, C, X, Y = [int(i) for i in input().split()]
if X < Y:
    ans = X*C*2+(Y-X)*B
else:
    ans = Y*C*2+(X-Y)*A
ans = min(A*X+B*Y, max(X, Y)*C*2, ans)
print(ans)
