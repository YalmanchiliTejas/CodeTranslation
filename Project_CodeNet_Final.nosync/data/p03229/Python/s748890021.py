n = int(input())
A = [int(input()) for _ in range(n)]
A.sort()
if n % 2 == 0:
  # 同じ長さ
  l = n // 2 - 1
  r = n - 1
  total = 0
  for i in range(n - 1):
    total += A[r] - A[l]
    if i % 2 == 0:
      l = (l + 1) % (n // 2)
    else:
      r -= 1
  print(total)
elif A[n // 2] - A[n // 2 - 1] < A[n // 2 + 1] - A[n // 2]:
  # 小さいほうが両端
  l = n // 2
  r = n - 1
  total = 0
  for i in range(n - 1):
    total += A[r] - A[l]
    if i % 2 == 0:
      l = (l + 1) % (n // 2 + 1)
    else:
      r -= 1
  print(total)
else:
  # 大きいほうが両端
  l = 0
  r = n // 2
  total = 0
  for i in range(n - 1):
    total += A[r] - A[l]
    if i % 2 == 0:
      r -= 1
      if r < n // 2:
        r = n - 1
    else:
      l += 1
  print(total)
