A,B,C,X,Y = map(int,input().split())

ans = 0
if A + B < C * 2:
    ans =  A * X + B* Y
else:
    ans = min(X,Y) * C * 2 
    x = min(X,Y)
    X -= x
    Y -= x
    
    ans += min(X * A + Y * B,X * C * 2+ Y * C * 2)

print(ans)