while True:
  n, m = map(int, input().split())
  if n == 0 and m == 0:
    break
  if n != 0 and m != 0:
    t_all = [0] + sorted(list(map(int, input().split())) + list(map(int, input().split())))
  else:
    t_all = [0] + sorted(map(int, input().split()))
  ans = 0
  for i in range(1, n + m + 1):
    ans = max(ans, t_all[i] - t_all[i - 1])
  print(ans)
