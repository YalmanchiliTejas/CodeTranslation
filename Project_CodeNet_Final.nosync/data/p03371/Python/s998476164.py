A,B,C,X,Y = (int(i) for i in input().split()) 
money = 0


if A+B >= C*2:
    if X > Y:
        if X*2*C >= Y*2*C+(X-Y)*A:
            money += Y*2*C+(X-Y)*A
        else:
            money += X*2*C
    else:
        if Y*2*C >= X*2*C+(Y-X)*B:
            money += X*2*C+(Y-X)*B
        else:
            money += Y*2*C
else:
    money += A*X + B * Y

print(money)