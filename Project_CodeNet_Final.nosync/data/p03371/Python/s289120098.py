A, B, C, X, Y = map(int, input().split())

xn, yn = 0, 0
price = 0

if A >= 2*C and X > xn:
    ammount = X - xn
    price += C * X * 2
    xn += X
    yn += X

if B >= 2*C and Y > yn:
    ammount = Y - yn
    price += C * ammount * 2
    xn += ammount
    yn += ammount

if (A+B) >= 2*C and (X - xn) >= 1 and (Y - yn) >= 1:
    ammount = min(X, Y)
    price += C * ammount * 2
    xn += ammount
    yn += ammount


if X - xn >= 1:
    price += A * (X - xn)

if Y - yn >= 1:
    price += B * (Y - yn)

print(price)


# min_price = 1 << 32 
# for i in range(max(X, Y)+1):
#     xn, yn = i, i
#     price = (2*C) * i
#     price += (max(0, X - xn)) * A
#     price += (max(0, Y - yn)) * B
#     min_price = min(min_price, price)
# 
# print(min_price)