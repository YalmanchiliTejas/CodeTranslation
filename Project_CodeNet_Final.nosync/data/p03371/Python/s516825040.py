A, B, C, X, Y = map(int, input().split())

min_price = A * X + B * Y

if A + B > 2 * C:
    while X > 0 and Y > 0:
        X = X - 1
        Y = Y - 1
        min_price -= A + B - 2 * C

if X > 0 and A > 2 * C:
    while X > 0:
        X = X - 1
        min_price -= A - 2 * C

if Y > 0 and B > 2 * C:
    while Y > 0:
        Y = Y - 1
        min_price -= B - 2 * C

print(min_price)
