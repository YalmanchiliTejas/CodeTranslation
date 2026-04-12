while True:

  n = int(raw_input())

  if n == 0:
    break

  l = []

  for i in range(n):
    l.append(int(raw_input()))

  print (sum(l) - max(l) - min(l)) / (n - 2)