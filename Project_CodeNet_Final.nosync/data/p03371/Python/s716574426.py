A,B,C,X,Y = map(int,input().split())
cost = 0

if A + B < 2*C:
    cost = cost + A*X + B*Y
    print(cost)
    exit()

elif A + B == 2*C:
    if min(X,Y) == X:
        cost = cost + 2*C*X
        if 2*C <= B:
            cost = cost + 2*C*(Y-X)
            print(cost)
            exit()
        else:
            cost = cost + B*(Y-X)
            print(cost)
            exit()

    else:
        cost = cost + C*2*Y
        if 2 * C <= A:
            cost = cost + 2 * C * (X - Y)
            print(cost)
            exit()
        else:
            cost = cost + A * (X - Y)
            print(cost)
            exit()

else:  #A+B > 2C
    if min(X, Y) == X:
        cost = cost + 2 * C * X
        if 2 * C <= B:
            cost = cost + 2 * C * (Y - X)
            print(cost)
            exit()
        else:
            cost = cost + B * (Y - X)
            print(cost)
            exit()

    else:
        cost = cost + C * 2 * Y
        if 2 * C <= A:
            cost = cost + 2 * C * (X - Y)
            print(cost)
            exit()
        else:
            cost = cost + A * (X - Y)
            print(cost)
            exit()

