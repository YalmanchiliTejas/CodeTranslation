a, b, c, x, y = map(int, input().split())

# 購入金額
price_a_b = 0
price_mix = 0
price_c = 0

# Aピザ、BピザをそれぞれX,Y枚購入する
price_a_b = a*x + b*y

# ABピザを、MIN(X,Y)*2枚購入し、Aピザ、Bピザどちらかの不足分を購入する
price_mix = c*min(x, y)*2 + a*(x-min(x, y)) + b*(y-min(x, y))

# ABピザをMAX(X,Y)枚購入する
price_c = c*max(x, y)*2

print(min(price_a_b, price_mix, price_c))
