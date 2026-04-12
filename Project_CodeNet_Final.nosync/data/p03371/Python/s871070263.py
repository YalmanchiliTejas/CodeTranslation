A, B, C, x, y = list(map(int, input().split()))

cost = 1e+15
for i in range(max(x, y)+1):
  xx = max(0, x - i)
  yy = max(0, y - i)
  cost = min(cost, A * xx + B * yy + 2*C*i)
print(cost)
