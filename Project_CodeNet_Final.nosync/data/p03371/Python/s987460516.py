# coding: utf-8

A, B, C, X, Y = map(int, input().split())

# ABピザはAとBの平均より安いか
mean_AB = (A + B) / 2

if mean_AB > C:
    if X <= Y:
        price = C * X * 2 + B * (Y-X)
        # ABピザがかなり安く、余りが出ても多めに買ってもよい場合か
        price_AB = C * Y * 2
        if price_AB < price:
            price = price_AB
    else:
        price = C * Y * 2 + A * (X-Y)
        # ABピザがかなり安く、余りが出ても多めに買ってもよい場合か
        price_AB = C * X * 2
        if price_AB < price:
            price = price_AB

else:
    price = A * X + B * Y

print(price)