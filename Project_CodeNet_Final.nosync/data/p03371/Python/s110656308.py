A, B, C, X, Y = list(map(lambda x: int(x), input().split(' ')))

ans = pow(10, 5) * max(A, B, C) * 3
ab_max = (max(X, Y)+1) * 2
for ab in range(0, ab_max + 1, 2):
    x = max(0, X - ab//2)
    y = max(0, Y - ab//2)
    price = x * A + y * B + ab * C
    # print((x, y, ab), price)
    ans = min(ans, price)

print(ans)
