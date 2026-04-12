while 1:
  n, a, b, c, x = map(int, raw_input().split())
  if not n:
    break
  i = f = 0
  y = map(int, raw_input().split())
  while f <= 10000:
    if x == y[i]:
      i += 1
    x = (a * x + b) % c
    if i == n:
      print f
      break
    f += 1
  else:
    print -1