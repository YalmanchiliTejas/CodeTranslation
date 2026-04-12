A, B, C, X, Y = map(int, input().split())

ans = 0
if (A + B) >= 2*C:
    minv = min(X, Y)
    ans += minv * 2*C
    X -= minv
    Y -= minv
    ans += min(A*X, X*2*C) + min(B*Y, Y*2*C)
    print(ans)

else:
    print(min(A*X + B*Y, max(X, Y)*2*C))