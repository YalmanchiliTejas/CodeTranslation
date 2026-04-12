A, B, C, X, Y = map(int, input().split())

is_ab = ((A+B)/2) >= C

amount = 0

if is_ab:
    amount += 2*C*min(X, Y)
    tmp = min(X, Y)
    X -= tmp
    Y -= tmp
    
    if X>0:
        if A>(2*C):
            amount += 2*C*X
        else:
            amount += A*X
    
    else:
        if B>(2*C):
            amount += 2*C*Y
        else:
            amount += B*Y

else:
    amount += (A*X+B*Y)

print(amount)