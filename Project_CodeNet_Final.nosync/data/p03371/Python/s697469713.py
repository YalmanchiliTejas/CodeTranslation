A, B, C, X, Y = [int(i) for i in input().split()]
price = 0
if A + B <= C*2:
    price += A*X+B*Y
else:
    price += C*2*min(X, Y)
    if A <= C*2 and X > Y:
        price += A*(X-Y)
    elif B <= C*2 and X < Y:
        price += B*(Y-X)
    else:
        price += C*2*abs(X-Y)
print(price)