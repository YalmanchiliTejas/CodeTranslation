n = int(input())

if n < 15:
  print(n * 800)
else:
  m = n // 15
  print(n * 800 - m * 200)