A, B, C, X, Y = list(map(int, input().split()))
ans = A * X + B * Y

for Z in range(10**5 + 1):
    Z *= 2
    price = A * max(X - Z//2, 0) + B * max(Y - Z // 2, 0) + C * Z
    ans = min(ans, price)

print(ans)