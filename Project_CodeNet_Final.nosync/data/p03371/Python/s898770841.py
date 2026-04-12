a, b, c, x, y = map(int, input().split())

ans1 = a * x + b * y
ans2 = c * 2 * max(x, y)
if x == y:
  ans3 = ans2
elif x > y:
  ans3 = c * 2 * y + a * (x - y)
else:
  ans3 = c * 2 * x + b * (y - x)
print(min(ans1, ans2, ans3))
