A,B,C,X,Y = map(int, input().split())

l = []

#パターン１ AとBだけ作るとき
price1 = A * X + B * Y
l.append(price1)

#パターン2 AB分割とあまり調整
if X > Y:
    if A < 2*C:
        price2 = 2 * Y * C + A * abs(X-Y)
        l.append(price2)
    else:
        price3 = 2 * Y * C + C * abs(X-Y) * 2
        l.append(price3)
elif X < Y:
    if B < 2*C:
        price4 = 2 * X * C + B * abs(Y-X)
        l.append(price4)
    else:
        price5 = 2 * X * C + C * abs(Y-X) * 2
        l.append(price5)

else:
    price6 = 2 * X * C
    l.append(price6)


print(min(l))