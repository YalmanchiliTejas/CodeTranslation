A,B,C,X,Y=map(int, input().split())

if A*X+B*Y<A*(X-1)+B*(Y-1)+C*2:
    price=A*X+B*Y
else:
    if 2*C<A and 2*C<B:
        price=max(X,Y)*2*C
    elif 2*C<A and 2*C>B and X>Y:
        price=X*2*C
    elif 2*C>A and 2*C<B and X<Y:
        price=Y*2*C
    else:
        if X>Y:
            price=2*C*Y+A*(X-Y)
        else:
            price=2*C*X+B*(Y-X)

print(price)
