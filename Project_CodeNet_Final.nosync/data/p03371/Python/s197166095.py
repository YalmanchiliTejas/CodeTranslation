A,B,C,X,Y = map(int, input().split())

ABpizza = C*2
cost = 0
if ABpizza <= A+B:
    tmp = min(X,Y)
    cost = cost + ABpizza * tmp
    X = X - tmp
    Y = Y - tmp

    if (cost + X*A + Y*B) >= (cost + (max(X,Y)*ABpizza)):
        cost = cost + ((max(X,Y)*ABpizza))
    else:
        cost = (cost + X*A + Y*B)
else:
    cost = (A*X) + (B*Y)

print(cost)