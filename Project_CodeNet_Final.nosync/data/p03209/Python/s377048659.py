import math
N,X = list(map(int, input().split()))
cnt = 0
for i in range(N, 0, -1):
  t = math.pow(2, i + 1) - 2
  if X >= t * 2:
    cnt += t + 1
    break
  elif X >= t:
    cnt += t / 2
    X -= t
    if X > 1:
      cnt += 1
      X -= 1
    elif X == 1:
      cnt += 1
      break
    else:
      break
  else:
    if X > 1:
      X -= 1
    else:
      break
print(int(cnt))