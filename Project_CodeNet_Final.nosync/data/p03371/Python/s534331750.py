A, B, C, X, Y = map(int, input().split())

price = min(A*X+B*Y, C*2 * (max(X, Y)))

is_break = 0

for i in range(100000):
    if price >= A*max(0, X - i) + B*max(0, Y - i)+2*C*i:
        price = A*max(0, X - i) + B*max(0, Y - i)+2*C*i
print(price)
