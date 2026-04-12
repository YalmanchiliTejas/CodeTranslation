n = int(input())
if 1 <= n <= 100:
  ans = 800 * n - 200 * (n // 15)
  print(ans)