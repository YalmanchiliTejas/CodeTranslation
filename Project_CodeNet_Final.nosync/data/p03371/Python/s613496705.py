A, B, C, X, Y = map(int,input().split())

if A + B <= 2 * C:
    ans = A * X + B * Y
else:
    if X <= Y:
        ans = 2 * C * X + (Y - X) * B
    else:
        ans = 2 * C * Y + (X - Y) * A
    
    if ans > 2 * C *(max(X, Y)):
        ans = 2 * C *(max(X, Y))

print(ans)
