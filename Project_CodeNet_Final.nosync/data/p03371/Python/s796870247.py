A, B, C, X, Y = map(int, input().split())

if (C>=(A+B)/2):
    price = A*X+B*Y
    print(price)
else:
    if(X>=Y):
        price = C*Y*2+A*(X-Y)
    else:
        price = C*X*2+B*(Y-X)
    print(min(price,C*2*max(X,Y)))
