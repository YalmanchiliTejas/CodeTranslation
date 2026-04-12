A, B, C, X, Y = map(int, input().split())
price = [0]*(max(X, Y)+1)
price[0] = A*X+B*Y
for i in range(1, max(X, Y)+1):
  price [i] = 2*C*i+A*max(0, X-i)+B*max(0,Y-i)
print(min(price))