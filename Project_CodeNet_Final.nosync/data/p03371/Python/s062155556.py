a, b, c, x, y = list(map(int, input().split()))
ans = []
if a + b > 2 * c:
  cost = 0
  mxy = min(x, y)
  cost += mxy * 2 * c
  ans.append(cost + (x - mxy)* a + (y - mxy) * b)
  ans.append(max(x, y) * c * 2)
else:
  ans.append(x * a + y * b)
print(min(ans))