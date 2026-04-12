# -*- coding: utf-8 -*-

# A,B,C,X,Yを取得
a, b, c, x, y = map(int, input().split())

price = 0
if a + b <= 2 * c:
    price = (a * x) + (b * y)
else:
    num_ab = min(x, y)
    price = 2 * c * num_ab

    if x > y:
        price += (x - y) * min(a, 2 * c)
    elif x < y:
        price += (y - x) * min(b, 2 * c)

# 結果を出力
print("{}".format(price))
