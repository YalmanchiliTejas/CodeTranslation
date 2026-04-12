while True:
  n, a, b, c, x = list(map(int, input().split()))
  if n==0:
    break

  y = list(map(int, input().split()))
  cnt = 0
  cur = 0
  while cnt<=10000:
    if x==y[cur]:
      cur += 1
    if cur==n:
      break
    x = (a*x+b)%c
    cnt += 1
  if cnt==10001:
    print(-1)
  else:
    print(cnt)
