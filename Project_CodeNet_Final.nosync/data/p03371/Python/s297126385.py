A,B,C,X,Y = map(int,input().split())

if A+B >= 2*C:
    planA = 2*C*max(X,Y)
    if X < Y:
        planB = 2*C*X + B * abs(X-Y)
    elif X > Y:
        planB = 2*C*Y + A * abs(X-Y)
    else:
        planB = planA
    
    ans = min(planA,planB)
else:
    ans = A*X + B*Y

print(ans)