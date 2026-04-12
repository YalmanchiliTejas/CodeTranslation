A,B,C,X,Y = map(int, input().split())
price = 0
if A+B > C*2:
    if X < Y:
        price += X * C * 2
        if B > C*2:
            price += (Y-X) * C*2
        else:
            price += (Y-X) * B

    else:
        price += Y * C * 2
        if A > C*2:
            price += (X-Y) * C*2
        else:
            price += (X-Y) * A

else:
    if A > C*2:
        price += X * C * 2
    else:
        price += X * A
    if B > C*2:
        price += Y * C * 2
    else:
        price += Y * B

print(price)
