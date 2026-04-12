A, B, C, X, Y = [int(x) for x in input().split(' ')]
if (A + B) / 2 > C:
  p = 10**10
  for i in range(min(X, Y), max(X, Y)+1):
    p = min(p, A * max(0, X-i) + B * max(0, Y-i) + C * i * 2)
  print(p)
else:
  print(A * X + B * Y)