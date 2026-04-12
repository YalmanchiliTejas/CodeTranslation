def pricing(A, B, C, tmp):
    A_price = tmp * A
    B_price = tmp * B
    AnB_price = A_price + B_price
    AB_price = tmp * 2 * C
    price = AnB_price if AnB_price < AB_price else AB_price
    return price


A, B, C, X, Y = map(int, input().split())
ans = 0
tmp = min(X, Y)
price = pricing(A, B, C, tmp)

if X > Y:
    tmp = max(X, Y) - tmp
    price += pricing(A, 0, C, tmp)
else:
    tmp = max(X, Y) - tmp
    price += pricing(0, B, C, tmp)

print(price)
