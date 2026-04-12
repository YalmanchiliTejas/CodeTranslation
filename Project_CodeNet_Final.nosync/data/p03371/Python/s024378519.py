a, b, c, x, y = map(int, input().split())
ans = 50000 * 10 ** 5
for i in range(max(x, y) + 1):
  ansa = max(x - i, 0)
  ansb = max(y - i, 0)
  sm = a * ansa + b * ansb + 2 * c * i 
  if ans > sm:
    ans = sm
print(ans)
