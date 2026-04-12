A, B, C, X, Y = map(int, input().split())

if 2 * C < A + B:
    if X <= Y:
        if 2 * C > B:
            cost = 2*C*X + (Y-X)*B
        else:
            cost = 2*C*Y
    else:
        if 2 * C > A:
            cost = 2*C*Y + (X-Y)*A
        else:
            cost = 2*C*X
else:
    cost = A*X + B*Y
print(cost)