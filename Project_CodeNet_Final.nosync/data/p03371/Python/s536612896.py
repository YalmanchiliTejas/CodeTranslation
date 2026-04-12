A , B , C , X ,Y = map(int,input().split())
A_val = A * X
B_val = B * Y
C_val = C * 2
ans = 0
if A + B >= C_val:
    if X >= Y:
        ans += Y * C_val
        remain = X - Y
        if A >= C_val:
            ans += C_val * remain
        else:
            ans += A * remain
    else:
        ans += X * C_val
        remain = Y - X
        if B >= C_val:
            ans += C_val * remain
        else:
            ans += B * remain
    print(ans)
else:
    print(A_val + B_val)