a, b, c, x, y = list(map(int, input().split()))

ans = float("INF")
for i in range(max(x, y)+1):
  t = c*2*i
  if x>i:
    t += (x-i)*a
  if y>i:
    t += (y-i)*b
  ans = min(ans, t)
print(ans)