A, B, C, X, Y = map(int, input().split())

total = 0
share = min(X, Y)
X -= share
Y -= share
if A+B <= 2*C:
    total += share * (A+B)
else:
    total += share * 2 * C

if X > 0:
    if A < 2 * C:
        total += A * X
    else:
        total += 2 * C * X

if Y > 0:
    if B < 2 * C:
        total += B * Y
    else:
        total += 2 * C * Y

print(total)
