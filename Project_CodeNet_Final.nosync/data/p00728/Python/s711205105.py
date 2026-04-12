while True:
  n = input();
  if n == 0:
    break;
  a = []
  for i in range(n):
    a.append(input());
  print (sum(a) - min(a) - max(a)) / (len(a) - 2)