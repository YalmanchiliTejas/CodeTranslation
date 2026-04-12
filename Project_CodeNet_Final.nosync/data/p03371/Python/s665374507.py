A, B, C, X, Y = map(int, input().split())
ans = float('inf')
for i in range(10**5 + 1):
  p = (C * i * 2) + (A * max(0, X - i)) + (B * max(0, Y - i))
  ans = min(ans, p)
print(ans)