A, B, C, X, Y = map(int, input().split())

# Cを買った個数とA、B単品で買った場合のコストを愚直に試す
total = 1<<60
for i in range(10**5+1):
  cost = 2*C*i + max(X-i, 0)*A + max(Y-i, 0)*B
  total = min(cost, total)

print(total)