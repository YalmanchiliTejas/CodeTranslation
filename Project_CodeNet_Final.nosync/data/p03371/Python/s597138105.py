a, b, c, x, y = map(int, input().split())
ans = 0

if 2*c-a-b > 0:
  ans += a*x + b*y
else:
  s = min(x, y)
  ans += min(c*s*2 + a*(x-s) + b*(y-s), c*max(x, y)*2)
print(ans)