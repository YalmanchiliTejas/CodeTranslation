a, b, c, x, y = map(int, input().split())
if a + b <= 2 * c:
  print(a*x + b*y)
else:
  ans = min(x, y) * 2 * c
  if x <= y:
    ans += min((y-x)*b, (y-x)*2*c)
  else:
    ans += min((x-y)*a, (x-y)*2*c)
  print(ans)