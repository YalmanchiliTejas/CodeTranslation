A,B,C,X,Y = map(int,input().split())
if A + B < 2 * C:
    ans = A * X + B * Y
else:
    ans = min(X,Y) * 2 * C
    if X < Y:
        Z = Y - X
        ans += Z * min(B,2*C)
    else:
        Z = X - Y 
        ans += Z * min(A,2*C)
print(ans)