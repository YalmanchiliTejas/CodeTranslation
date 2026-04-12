A,B,C,X,Y = map(int,input().split())
ans = 0
if A+B >= 2*C:
    sub = min(X,Y)
    ans += 2*C * sub
    X -= sub
    Y -= sub
    left = max(X,Y)
    yen = [A,B][X<Y]
    if yen >= 2*C:
        ans += 2*C*left
        X=Y=0
ans += A*X+B*Y
print(ans)