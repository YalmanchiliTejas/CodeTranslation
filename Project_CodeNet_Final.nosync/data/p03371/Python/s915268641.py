A, B, C, X, Y = map(int, input().split())
ans = 0
if X <= Y:
    if A + B <= 2*C:
        ans += (A + B)*X
    else:
        ans += 2*C*X
    ans += min(B, 2*C)*(Y - X)
else:
    if A + B <= 2*C:
        ans += (A + B)*Y
    else:
        ans += 2*C*Y
    ans += min(A, 2*C)*(X - Y)

print(ans)
