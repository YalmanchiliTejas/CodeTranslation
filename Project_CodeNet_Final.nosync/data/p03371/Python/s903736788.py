A,B,C,X,Y = map(int, input().split())

ans = 0
if C*2 < A+B:
    ans += C * 2 * min(X, Y)
    if X > Y:
        if A < C*2:
            ans += (X-Y) * A
        else:
            ans += (X-Y) * C * 2
    else:
        if B < C*2:
           ans += (Y-X) * B
        else:
           ans += (Y-X) * C * 2
else:
    ans += X*A + B*Y
print(ans)