A,B,C,X,Y=map(int,input().split())
ans=0
if X < Y:
    X,Y = Y,X
    A,B = B,A
if A+B > 2*C:
    ans = Y * C * 2
    if A > 2*C:
       ans += (X-Y) * C * 2
    else:
       ans += (X-Y) * A
else:
    ans = A*X + B*Y
print(ans)
