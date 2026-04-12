A, B, C, X, Y = map(int, input().split())

TotalPrice = 2 * 5000 * 10**5
for i in range(max(X, Y) + 1):
    priceA = A * max(X - i, 0)
    priceB = B * max(Y - i, 0)
    priceC = 2 * C * i
    TotalPrice = min(TotalPrice, priceA + priceB + priceC)

print(TotalPrice)
