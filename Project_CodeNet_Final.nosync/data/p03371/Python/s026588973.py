A,B,C,X,Y = map(int, input().split())
ans = 0
if (A + B)  >= C * 2:
    if X < Y:
        ans += X * C * 2
        Y -= X
        if B <= C * 2:
            ans += B * Y
        else:
            ans += C * Y * 2
    elif X > Y:
        ans += Y * C * 2
        X -= Y
        if A <= C * 2:
            ans += A * X
        else:
            ans += C * X * 2
    else:
        ans += X * C * 2
else:
    ans += A * X + B * Y

print(ans)
