A, B, C, X, Y = map(int,input().split())
import math
price_min = -1
for ab in [0, 2*X, 2*Y]:
    X_need = X - 0.5*ab
    Y_need = Y - 0.5*ab
    if X_need < 0:
        X_need = 0
    if Y_need < 0:
        Y_need = 0
    price = ab * C + A * math.ceil(X_need) + B * math.ceil(Y_need)
    if price_min == -1:
        price_min = price
    else:
        price_min = min(price, price_min)
print(price_min)
