import sys
A,B,C,X,Y = map(int,input().split())
ans = 0
if A+B > 2*C:
    judge = True
else:
    ans += X*A
    ans += Y*B
    print(ans)
    sys.exit()

    # judge = False

if judge:
    min_XY = min(X,Y)
    if min_XY == 0:
        ans += X*A
        ans += Y*B
        print(ans)
        sys.exit()
    else:
        X -= min_XY
        Y -= min_XY
        ans += 2*C*min_XY
        if X !=0:
            if 2*C*X < A*X:
                ans +=  2*C*X
            else:
                ans += A*X
        if Y !=0:
            if 2*C*Y < B*Y:
                ans +=  2*C*Y
            else:
                ans += B*Y
    print(ans)