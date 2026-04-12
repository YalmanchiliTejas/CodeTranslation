while True:
  n, a, b, c, x = map(int, raw_input().split())
  if n + a + b + c + x == 0: break
  ys = map(int, raw_input().split())
  cnt = 0
  reel = 0
  while True:
    if x == ys[reel]:
      reel += 1
      if reel == n:
        break

    x = (a * x + b) % c
    cnt += 1
    if cnt > 10000:
      cnt = -1
      break
  print cnt