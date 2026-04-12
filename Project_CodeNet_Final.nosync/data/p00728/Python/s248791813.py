while(True):
  n = input()
  if n == 0:
    break;
  sl = 1001
  sh = 0
  ret = 0
  for i in range(n):
    tmp = input()
    ret += tmp
    if tmp < sl:
      sl = tmp
    if tmp > sh:
      sh = tmp
  ret -= (sl + sh)
  print "%d" % (ret/(n-2))