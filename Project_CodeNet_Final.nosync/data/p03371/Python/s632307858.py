import sys
input = sys.stdin.readline

A, B, C, X, Y = [int(x) for x in input().strip().split()]
ans = 0

if A > 2*C and B > 2*C:
    print(max(X, Y) * 2 * C)
else:
    if (A + B) >= 2 * C:
        minXY = min(X, Y)
        ans += minXY * 2 * C
        X -= minXY
        Y -= minXY
    if X:
        if A < 2 * C:
            ans += X * A
        else:
            ans += X * 2 * C
    if Y:
        if B < 2 * C:
            ans += Y * B
        else:
            ans += Y * 2 * C
    print(ans)
        
