A, B, C, X, Y = map(int, input().split())
price = A*X + B*Y
tmp = 0
for i in range(1, int(1 + 10e5)):
    tmp = 2*C*i + max(0, X-i)*A + max(0, Y-i)*B
    price = min(price, tmp)
print(price)            