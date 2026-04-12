A,B,C,X,Y = list(map(int, input().split()))

ans = 0
for i in range(1, max(X,Y)+1):
    x = 1
    y = 1
    if X <= 0: x = 0
    if Y <= 0: y = 0
    ab_price = A * x + B * y
    c_price = C * 2

    if ab_price >= c_price:
        ans += C * 2
    else:
        _x = 0
        if x > 0:
          _x = 1
        _y = 0
        if y > 0:
          _y = 1
        ans += A * _x + B * _y
    X -= 1
    Y -= 1
print(ans)