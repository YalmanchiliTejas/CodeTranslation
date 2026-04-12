A, B, C, X, Y = map(int, input().split())
ans = 10**18
Z = max(X, Y)
for i in range(Z+1):
  price = 2*C*i + A*max(0, X-i) + B*max(0, Y-i)
  ans = min(ans, price)

print(ans)