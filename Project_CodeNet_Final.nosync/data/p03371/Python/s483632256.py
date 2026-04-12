a, b, c, x, y = map(int, input().split())
ans = float("inf")
for i in range(max(x, y)+1):
  t = a*max(0, x-i) + b*max(0, y-i) + c*2*i
  ans = min(ans, t)
print(ans)