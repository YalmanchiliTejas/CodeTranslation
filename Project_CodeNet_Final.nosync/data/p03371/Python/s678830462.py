A, B, C, X, Y = map(int, input().split())

# A ピザ p 枚、 B ピザ q 枚、 C ピザ r 枚　（c は偶数）
# p + r // 2 >= X
# q + r // 2 >= Y
# A * p + B * q + C * r を最小にする

# r を基準にしてループを回す

max_r = max(X, Y) * 2 

cost = float('inf')

for r in range(0, max_r+2, 2):
  p = max(X - r // 2, 0)
  q = max(Y - r // 2, 0)
  tmp_cost = A * p + B * q + C * r  
  cost = min(cost, tmp_cost)
  
print(cost)