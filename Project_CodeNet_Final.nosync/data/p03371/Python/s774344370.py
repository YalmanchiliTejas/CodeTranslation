A, B, C, X, Y = map(int,input().split())
ans = A*X+B*Y
if X < Y:
    ans = min(ans, 2*Y*C)
    ans = min(ans, 2*X*C+(Y-X)*B)
else:
    ans = min(ans, 2*X*C)
    ans = min(ans, 2*Y*C+(X-Y)*A)
print(ans)
