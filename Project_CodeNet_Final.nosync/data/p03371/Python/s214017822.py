A, B, C, X, Y = map(int, input().split())

if (A+B) > C*2 :
    ans = min(X,Y)*2*C
    
else:
    ans = A*min(X,Y) + B*min(X,Y)
    
remain = max(X,Y) - min(X,Y)

rem_C = remain*C
rem_AorB = remain*(A,B)[X<Y]

if rem_C*2 < rem_AorB:
    ans += rem_C*2
else:
    ans += rem_AorB

print(ans)
