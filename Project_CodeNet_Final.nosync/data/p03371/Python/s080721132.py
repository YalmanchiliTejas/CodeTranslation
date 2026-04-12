A, B, C, X, Y = map(int,input().split())

if A+B < 2*C:
    ans = (A*X + B*Y)
elif A > 2*C and B > 2*C:
    ans = 2*C*max(X,Y)
elif A > 2*C:
    ans = 2*C*X + B*max(0,(Y-X))
elif B > 2*C:
    ans = 2*C*Y + A*max(0,X-Y)
else:
    ans = 2*C*min(X,Y) + A*max(0,X-Y) + B*max(0,Y-X)

print(ans)