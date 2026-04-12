def check():
    A, B, C, X, Y = [int(i) for i in input().split(' ')]
    if X > 0 and Y > 0:
        if 2*C < A+B:
            if X > Y:
                total = Y*2*C
                price = min(A, 2*C)
                total += (X-Y)*price
            else:
                total = X*2*C
                price = min(B, 2*C)
                total += (Y-X)*price
        else:
            total = A*X + B*Y
    elif X == 0:
        price = min(B, 2*C)
        total = price*Y
    else:
        price = min(A, 2*C)
        total = price*X
        
    print(total)
check()