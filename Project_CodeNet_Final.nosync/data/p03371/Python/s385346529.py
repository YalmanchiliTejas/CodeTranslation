A, B, C, X, Y = map(int, input().split())

cost = 0
n_small = min(X, Y)

if A + B > 2*C:
    cost += n_small * (2*C)
else:
    cost += n_small * (A+B)

X -= n_small
Y -= n_small

if X == 0:
    if B > 2*C:
        cost += Y * (2*C)
    else:
        cost += Y * B
else:
    if A > 2*C:
        cost += X * (2*C)
    else:
        cost += X * A
        
print(cost)