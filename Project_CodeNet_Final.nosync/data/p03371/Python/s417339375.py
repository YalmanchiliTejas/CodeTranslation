A, B, C, X, Y = map(int, input().split())

if A+B <= 2*C:
    ans = X*A + Y*B
else:
    z = min(X, Y)
    if z == X:
        c = B
    else:
        c = A
    ans = C*2*z
    Z = max(X, Y) - z
    if c <= 2*C:
        ans += c*Z
    else:
        ans += 2*C*Z
    
print(ans)