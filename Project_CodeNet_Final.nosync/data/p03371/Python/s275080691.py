#Half and Half
A,B,C,X,Y=map(int,input().split())
if X>=Y:
    more=X
    more_price=A
    less=Y
else:
    more=Y
    more_price=B
    less=X
if more_price>=C*2:
    price=C*2*more
else:
    if A+B>=2*C:
            price=C*2*less+(more-less)*more_price
        
    else:
        price=A*X+B*Y
print(price)

