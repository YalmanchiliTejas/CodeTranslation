while True:
  n = int(input())
  if n==0:
    break
  a = [int(input()) for _ in range(n)]
  a.sort()
  print(sum(a[1:n-1])//(n-2))
