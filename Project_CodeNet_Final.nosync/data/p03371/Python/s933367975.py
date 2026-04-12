A,B,C,X,Y = map(int,input().split())
ans = 0
if 2*C <= A+B:
    Z = min(X,Y)
    ans = 2*C*Z
    X -= Z
    Y -= Z
ans += min(2*C*X,A*X)
ans += min(2*C*Y,B*Y)
print(ans)