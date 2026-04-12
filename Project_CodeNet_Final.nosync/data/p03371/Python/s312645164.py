l = raw_input().split()
A = int(l[0])
B = int(l[1])
C = int(l[2])
X = int(l[3])
Y = int(l[4])

cost = 0

if A+B <= 2*C:
    cost = A * X + B * Y
else:
    if X  == Y:
        cost = 2 * C * X
    elif X > Y:
        if A <= C  * 2:
            cost = 2 * C * Y + A * ( X -  Y )
        else:
            cost  = 2 * C * X
    else:
        if B <= C * 2:
            cost = 2 * C * X + B * ( Y - X )
        else:
            cost = 2 * C * Y

print(cost)
