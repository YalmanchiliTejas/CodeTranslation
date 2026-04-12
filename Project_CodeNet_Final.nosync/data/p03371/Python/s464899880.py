A, B, C, X, Y = map(int, input().split())
C *= 2
ans = 0

if A+B <= C:
    ans = A*X + B*Y
    print(ans)
else:
    ans = C*min(X,Y)
    if X>=Y:
        if A >=C:
            ans += (X-Y)*C
        else:
            ans += (X-Y)*A
    else:
        if B>=C:
            ans += (Y-X)*C
        else:
            ans += (Y-X)*B
    print(ans)