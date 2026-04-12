A, B, C, X, Y = map(int, input().split())
price = A * X + B * Y
x = X
y = Y

for i in range(max(X, Y)):
    if x > 0 and y > 0:
        d = A + B - C * 2
    elif x <= 0:
        d = B - C * 2
    elif y <= 0:
        d = A - C * 2

    price = min(price, price - d)
    x -= 1
    y -= 1

print(price)