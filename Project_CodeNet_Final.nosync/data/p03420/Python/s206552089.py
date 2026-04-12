n, k = map(int, input().split())

ans = 0
for b in range(k + 1, n + 1):
  ans += (n // b) * (b - k) + max((n % b) - k + 1, 0)

if k == 0:
  print(ans - n)
else:
  print(ans)