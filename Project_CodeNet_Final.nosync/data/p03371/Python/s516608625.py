A, B, C, X, Y = list(map(int, input().split()))

if A+B <= 2*C:
    cost = A*X + B*Y
else:
    if X >= Y:
        if A < 2*C:
            cost = Y*2*C + (X -Y)*A
        else:
            cost = X*2*C
    else:
        if B < 2*C:
            cost = X*2*C + (Y-X)*B
        else:
            cost = Y*2*C

print(cost)