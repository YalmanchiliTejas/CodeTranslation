A, B, C, X, Y = map(int, input().split())
if (A+B)/2 <= C:
    ans = A*X+B*Y
else:
    if X <= Y:
        ans = 2*X*C
        if (Y-X)*B <= (Y-X)*2*C:
            ans += (Y-X)*B
        else:
            ans += (Y-X)*2*C
    else:
        ans = 2*Y*C
        if (X-Y)*A <= (X-Y)*2*C:
            ans += (X-Y)*A
        else:
            ans += (X-Y)*2*C
print(ans)