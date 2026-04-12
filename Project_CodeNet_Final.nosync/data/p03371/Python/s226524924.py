A, B, C, X, Y = list(map(int, input().split()))
C *= 2
ans = 0

if A >= C and B >= C:
    ans += max(X, Y) * C
elif C >= A+B:
    ans += A*X + B*Y
elif C >= max(A,B):
    if X>Y:
        ans += Y*C + (X-Y)*A
    else:
        ans += X*C + (Y-X)*B
else:
    if A >= C:
        ans += X*C
        if Y-X>0:
            ans+=(Y-X)*B
    else:
        ans += Y*C
        if X-Y>0:
            ans+=(X-Y)*A

print(ans)