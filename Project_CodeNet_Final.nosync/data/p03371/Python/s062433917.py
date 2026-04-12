A, B, C, X, Y = map(int, input().split())
price = A * X + B * Y
ma, mi = (X, Y) if X > Y else (Y, X)
ma_p, mi_p = (A, B) if X > Y else (B, A)

for i in range(1, ma+1):
    if i <= mi:
        temp = price - (ma_p + mi_p) + 2 * C
        if price > temp:
            price = temp
    else:
        temp = price - ma_p + 2 * C
        if price > temp:
            price = temp

print(price)