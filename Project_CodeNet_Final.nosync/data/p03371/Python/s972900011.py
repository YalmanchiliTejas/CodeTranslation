A, B, C, X, Y = map(int, input().split())

ans = 0
if A+B > 2*C:
    if X >= Y:
        ans += 2*C*Y
        if A > 2*C:
            ans += 2*C*(X-Y)
        else:
            ans += A*(X-Y)
    else:
        ans += 2*C*X
        if B > 2*C:
            ans += 2*C*(Y-X)
        else:
            ans += B*(Y-X)
else:
    ans += X*A + Y*B

print(ans)
