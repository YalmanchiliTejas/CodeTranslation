A,B,C,X,Y = list(map(int,input().split()))

if A+B <= 2*C:
    ans = A*X+B*Y
else:
    ans = 2*C*min(X,Y)
    if X > Y:
        if A > 2*C:
            ans += 2*C*(X-Y)
        else:
            ans += A*(X-Y)
    elif X < Y:
        if B > 2*C:
            ans += 2*C*(Y-X)
        else:
            ans += B*(Y-X)

print(ans)