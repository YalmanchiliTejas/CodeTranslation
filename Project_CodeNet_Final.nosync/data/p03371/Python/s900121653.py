A,B,C,X,Y = map(int,input().split())

if X < Y:
    A,B,X,Y = B,A,Y,X

ans = 0
if A + B >= 2*C:
    ans += Y*2*C
    X,Y = X-Y,0
    if A > 2*C:
        ans += X*2*C
    else:
        ans += X*A
else:
    ans += A*X+B*Y

print(ans)
