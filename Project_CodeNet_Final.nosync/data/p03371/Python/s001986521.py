A, B, C, X, Y = map(int, input().split())
#初期値
x = X ; y = Y
mn = 1e10
if 2*C-(A+B) >= 0 :
    ans = A * x + B * y
    print(ans)
else :
    for z in range(0,max(X,Y)*2+1,2) :
        if x > 0 and y > 0 :
            ans = A*x + B*y + C*z
            mn = min(mn,ans)
            x -= 1 ; y -= 1
        elif x > 0 and y == 0 :
            ans = A*x + C*z
            mn = min(mn, ans)
            x -= 1
        elif x == 0 and y > 0 :
            ans = B*y + C*z
            mn = min(mn, ans)
            y -= 1
        else :
            ans = C*z
            mn = min(mn, ans)
    print(mn)
