A, B, C, X, Y = map(int, input().split())
ans = 0
if A+B <= 2*C:
    ans += (A+B)*min(X,Y)
else:
    ans += 2*C*min(X,Y)

if X == Y:
    print(ans)
elif X < Y:
    if B <= 2*C:
        ans += B*(Y-X)
    else:
        ans += 2*C*(Y-X)
    print(ans)
else:
    if A <= 2*C:
        ans += A*(X-Y)
    else:
        ans += 2*C*(X-Y)
    print(ans)