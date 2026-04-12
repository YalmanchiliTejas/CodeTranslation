A, B, C, X, Y = map(int, input().split())

ans = 0
if 2*C < A+B:
    if X <= Y:
        ans += 2*C*X
        if 2*C < B:
            ans += (Y-X)*2*C
        else:
            ans += (Y-X) * B
    else:
        ans += 2*C*Y
        if 2*C < A:
            ans += (X-Y)*2*C
        else:
            ans += (X-Y) * A
else:
    if X <= Y:
        ans += X*(A+B)
        if 2*C < B:
            ans += (Y-X)*2*C
        else:
            ans += (Y-X) * B
    else:
        ans += Y*(A+B)
        if 2*C < A:
            ans += (X-Y)*2*C
        else:
            ans += (X-Y) * A

print(ans)