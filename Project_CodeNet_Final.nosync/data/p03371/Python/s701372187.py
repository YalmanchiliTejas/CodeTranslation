a, b, c, x, y = [int(i) for i in input().split()]
ans = (a + b + c) * (x + y)
for i in range(max(x, y) + 1):
  ans = min(2 * c * i + a * max(x - i, 0) + b * max(y - i, 0), ans)
print(ans)