A, B, C, X, Y = [int(i) for i in input().split()]

price = min(A+B, 2*C) * min(X, Y)
need_A = max(0, X-Y)
need_B = max(0, Y-X)

if need_A > 0:
    price += need_A * min(A, 2*C)
if need_B > 0:
    price += need_B * min(B, 2*C)

print(price)