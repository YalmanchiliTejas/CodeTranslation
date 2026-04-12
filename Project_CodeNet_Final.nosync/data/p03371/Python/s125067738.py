A, B, C, X, Y = map(int, input().split())
if A+B <= 2*C:
    ans = A*X+B*Y
else:
    c = min(X, Y)
    x = X-c
    y = Y-c
    ans = 2*C*c +min(A*x+B*y, 2*C*x+2*C*y)
print(ans)