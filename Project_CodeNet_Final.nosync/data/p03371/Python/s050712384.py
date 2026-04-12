A, B, C, X, Y = list(map(int, input().split()))
a, b, c = 0, 0, 0
if(A + B <= 2*C):
    a, b = X, Y
else:
    c = min(X, Y) * 2
    if(X > Y):
        if(A > 2*C):
            c += (X - Y) * 2
        else:
            a = (X - Y)
    else:
        if(B > 2*C):
            c += (Y - X) * 2
        else:
            b = (Y - X)


price = a*A + b*B + c*C
print(price)

