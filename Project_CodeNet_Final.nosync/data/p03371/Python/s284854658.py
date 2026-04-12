a, b, c, x, y = map(int, input().split())
ans = 1000000000000
for i in range(100001):
  ans = min(2 * c * i + max(0, x-i) * a + max(0, y-i) * b, ans)
print(ans)