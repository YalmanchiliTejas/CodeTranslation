A,B,C,X,Y = map(int,input().split())

money = 0
if A + B >= C*2:
    t = min(X,Y)
    money += t * 2 * C
    X -= t
    Y -= t
    if X > 0:
        if A > C*2:
            money += C * 2 * X
        else:
            money += A * X
    elif Y > 0:
        if B > C*2:
            money += C * 2 * Y
        else:
            money += B * Y
else:
    money += A * X + B * Y
print(money)
