def sub():
  import sys
  input = sys.stdin.readline
  n = int(input())
  a1 = int(input())
  a = [a1]
  ap = a.append
  for _ in range(n-1):
    ai = int(input())
    if ai <= a[-1]:
      ap(ai)
    elif ai > a[0]:
      a[0] = ai
    else:
      h = 0
      l = len(a)-1
      while l-h>1:
        m = (l+h)//2
        if ai > a[m]:
          l = m
        else:
          h = m
      a[l] = ai
  print(len(a))   
sub()