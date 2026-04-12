A,B,C,X,Y = map(int,input().split())
if A+B <= 2*C:
    ans = A*X + B*Y
else:
    ans = min(X,Y) * 2 * C
    if X > Y:
        ans += (X-Y) * min(A,2*C)
    elif X < Y:
        ans += (Y-X) * min(B,2*C)
print(ans)