while(True):
  n = int(input())
  if n == 0:
    quit()
  a = []
  for i in range(n):
    a.append(int(input()))
  a.sort()
  a = a[1:-1]
  ans = 0
  for j in a:
    ans += j
  print(ans//len(a))

