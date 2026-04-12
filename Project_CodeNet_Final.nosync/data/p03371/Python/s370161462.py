A, B, C, X, Y = map(int, input().split())

price = 0

if A+B > 2*C:
    if X >= Y:
        price += 2*C*Y
        remain = X-Y
        if A >= 2*C:
            price += 2*C*remain
        else:
            price += A*remain
    else:
        price += 2*C*X
        remain = Y-X
        if B >= 2*C:
            price += 2*C*remain
        else:
            price += B*remain
else:
    if X >= Y:
        price += (A+B)*Y
        remain = X-Y
        if A >= 2*C:
            price += 2*C*remain
        else:
            price += A*remain
    else:
        price += (A+B)*X
        remain = Y-X
        if B >= 2*C:
            price += 2*C*remain
        else:
            price += B*remain

print(price)
