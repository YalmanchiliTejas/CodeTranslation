A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for ab in range(0, 2 * (max(X, Y) + 1), 2):
  cost = ab * C + max(0, (X - ab // 2)) * A + max(0, (Y - ab // 2)) * B
  ans = min(ans, cost)
print(ans)