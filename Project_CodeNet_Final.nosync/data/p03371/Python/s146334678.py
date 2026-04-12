I = [int(i) for i in input().split()]
A, B, AB, X, Y = I

ans = 1e+15
for i in range(max(X,Y)+1):
  price = A*max(X-i, 0) + B*max(Y-i, 0) + AB*2*i
  ans = min(ans, price)
print(ans)