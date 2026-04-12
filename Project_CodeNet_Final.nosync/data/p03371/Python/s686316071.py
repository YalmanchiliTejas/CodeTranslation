a, b, c, x, y = map(int, input().split())
k = min(x, y)
ans = 0
if a + b >= 2 * c:
  ans += 2 * k * c
  if x >= y:
    ans += min((x - k) * a, 2 * c * (x - k))
  elif x < y:
    ans += min((y - k) * b, 2 * c * (y - k))
else:
  ans += x * a + y * b
print(ans)