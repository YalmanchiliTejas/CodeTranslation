a, b, c, x, y = map(int, input().split())
ans = 10 ** 15
for i in range(max(x, y) * 2 + 1):
  n = c * i * 2 + max(0, x - i) * a + max(0, y - i) * b
  ans = min(ans, n)
print(ans)  