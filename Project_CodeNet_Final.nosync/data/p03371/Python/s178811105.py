A, B, C, X, Y = map(int, input().split())
ans = 0
mxy = min(X, Y)
if 2*C <= A + B:
    ans += 2*C * mxy
else:
    ans += (A+B) * mxy
X -= mxy
Y -= mxy
if X == 0:
    if 2*C <= B:
        ans += 2*C * Y
    else:
        ans += B * Y
elif Y == 0:
    if 2*C <= A:
        ans += 2*C * X
    else:
        ans += A * X
print(ans)