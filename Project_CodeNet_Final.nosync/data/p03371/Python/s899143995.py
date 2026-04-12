A, B, C, X, Y = map(int, input().split())

if X < Y:
    temp = A
    A = B
    B = temp
    temp = X
    X = Y
    Y = temp

# Aピザを購入する
lower_price = 0

# 0 - X枚まで
for i in range(0, X + 1, 1):
    # Aピザ i枚と、Cピザ 2(X-i)枚を購入する
    price_a = A * i + C * 2 * (X - i)
    price_b = 0
    # Bピザの枚数が多い場合、不足分Bピザを購入する
    if X - i < Y:
        price_b = B * (Y - (X - i))
    price = price_a + price_b
    if lower_price == 0 or price < lower_price:
        lower_price = price

print(lower_price)
